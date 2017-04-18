cmake_minimum_required(VERSION 3.0)
project(Pineapple)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(Build/CMake/DownloadProject/DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             release-1.8.0
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

get_filename_component(PA_ROOT "." ABSOLUTE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Build/CMake")

find_package(opengl REQUIRED)
find_package(glew REQUIRED)
find_package(fmod REQUIRED)

# Header only libs checked into Ext
set(EXT_INCLUDE_DIRS ${PA_ROOT}/Ext)

function(glob_source_files _SOURCES)
    get_filename_component(_src_root_path "." ABSOLUTE)
    file(
        GLOB_RECURSE _glob_sources
        LIST_DIRECTORIES false
        "${_src_root_path}/*.c*"
        "${_src_root_path}/*.h*"
        "${_src_root_path}/*.inl"
    )
    set(${_SOURCES} ${_glob_sources} PARENT_SCOPE)
endfunction()

function(create_source_groups _SOURCES)
    set( _SOURCES_LIST ${_SOURCES} ${ARGN} )
    get_filename_component(_src_root_path "." ABSOLUTE)
    foreach(_source IN ITEMS ${_SOURCES_LIST})
        get_filename_component(_source_path "${_source}" PATH)
        file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
        string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
        source_group("${_group_path}" FILES "${_source}")
    endforeach()
endfunction()

function(add_pineapple_app _TARGET _SOURCES)
    set( _SOURCES_LIST ${_SOURCES} ${ARGN} )
    add_executable(${_TARGET} WIN32 ${_SOURCES_LIST})

    target_link_libraries(${_TARGET} paEngine paWindows paFMOD paOpenGL ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${FMOD_LIBRARIES})
    
    add_custom_command(
            TARGET ${_TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_CURRENT_LIST_DIR}/Assets
                    ${CMAKE_CURRENT_BINARY_DIR}/Assets)
                    
    add_custom_command(
            TARGET ${_TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PA_ROOT}/Assets
                    ${CMAKE_CURRENT_BINARY_DIR}/Assets)

    foreach(_library IN ITEMS ${FMOD_LIBRARIES})
        string(REPLACE "_vc.lib" ".dll" _dll ${_library})
        add_custom_command(
            TARGET ${_TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                    ${_dll}
                    ${CMAKE_CURRENT_BINARY_DIR})
    endforeach()
endfunction()

set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:Debug>:PA_DEBUG>
)

include_directories(Source ${EXT_INCLUDE_DIRS})

set_property(GLOBAL PROPERTY USE_FOLDERS ON) # To be able to sort projects into folders

set_target_properties (gtest PROPERTIES FOLDER Test/gtest)
set_target_properties (gtest_main PROPERTIES FOLDER Test/gtest)
set_target_properties (gmock PROPERTIES FOLDER Test/gtest)
set_target_properties (gmock_main PROPERTIES FOLDER Test/gtest)

add_subdirectory(Source/Pineapple/Engine)
add_subdirectory(Source/Pineapple/Graphics/OpenGL)
add_subdirectory(Source/Pineapple/Sound/FMOD)
add_subdirectory(Source/Pineapple/Platform/Windows)

set_target_properties (paEngine PROPERTIES FOLDER Engine)
set_target_properties (paOpenGL PROPERTIES FOLDER Plugins)
set_target_properties (paFMOD PROPERTIES FOLDER Plugins)
set_target_properties (paWindows PROPERTIES FOLDER Plugins)

# Tests
add_subdirectory(Test/Engine)
set_target_properties (paEngineTest PROPERTIES FOLDER Test)

# Demos
add_subdirectory(Demo/SpaceRocks)
add_subdirectory(Demo/HelloWorld)
add_subdirectory(Demo/CatchTheClown)
add_subdirectory(Demo/Simple)
add_subdirectory(Demo/Text)
set_target_properties (SpaceRocks PROPERTIES FOLDER Demo)
set_target_properties (HelloWorld PROPERTIES FOLDER Demo)
set_target_properties (CatchTheClown PROPERTIES FOLDER Demo)
set_target_properties (Simple PROPERTIES FOLDER Demo)
set_target_properties (Text PROPERTIES FOLDER Demo)
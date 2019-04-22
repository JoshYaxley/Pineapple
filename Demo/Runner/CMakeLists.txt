cmake_minimum_required(VERSION 3.0)
project(Runner)

glob_source_files(RUNNER_SOURCES)
create_source_groups(${RUNNER_SOURCES})

add_pineapple_app(Runner ${RUNNER_SOURCES})
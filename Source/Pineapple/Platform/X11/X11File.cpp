/*------------------------------------------------------------------------------
  Pineapple Game Engine - Copyright (c) 2011-2017 Adam Yaxley
  This software is licensed under the Zlib license (see license.txt for details)
------------------------------------------------------------------------------*/

#include <Pineapple/Engine/Platform/FileSystem.h>

std::unique_ptr<pa::FileSystem> pa::MakeInternal::fileSystem(pa::PlatformSettings::FileSystem settings)
{
	// The default file system works for Linux platforms
	return std::make_unique<pa::FileSystem>(settings);
}

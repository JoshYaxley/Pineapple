#pragma once

#include <Pineapple/Pineapple.h>

struct Resource
{
	std::shared_ptr<pa::Texture> background0;
	std::shared_ptr<pa::Texture> background1;
	std::shared_ptr<pa::Texture> background2;
	std::shared_ptr<pa::Texture> background3;
	std::shared_ptr<pa::Texture> background4;

	std::shared_ptr<pa::Texture> floor;

	std::shared_ptr<pa::Texture> playerRunning;
	
	void create(std::shared_ptr<pa::Platform> platform);
};

extern Resource g_resource;
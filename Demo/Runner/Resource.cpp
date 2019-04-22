#include "Resource.h"

Resource g_resource;

void Resource::create(std::shared_ptr<pa::Platform> platform)
{
	background0 = platform->getGraphics()->createTexture("background0.png");
	background1 = platform->getGraphics()->createTexture("background1.png");
	background2 = platform->getGraphics()->createTexture("background2.png");
	background3 = platform->getGraphics()->createTexture("background3.png");
	background4 = platform->getGraphics()->createTexture("background4.png");

	floor = platform->getGraphics()->createTexture("floor.png");

	playerRunning = platform->getGraphics()->createTexture("playerRunning.png");
	playerJumping = platform->getGraphics()->createTexture("playerJumping.png");
}
#include "Resource.h"

Resource g_resource;

void Resource::create(std::shared_ptr<pa::Platform> platform)
{
	background0 = platform->getGraphics()->createTexture("background0.png");
	background0->load();
	background1 = platform->getGraphics()->createTexture("background1.png");
	background1->load();
	background2 = platform->getGraphics()->createTexture("background2.png");
	background2->load();
	background3 = platform->getGraphics()->createTexture("background3.png");
	background4->load();
	background4 = platform->getGraphics()->createTexture("background4.png");
	background4->load();

	playerRunning = platform->getGraphics()->createTexture("playerRunning.png");
	playerRunning->load();
}
#include <Pineapple/Pineapple.h>

#include "ParallaxBackground.h"
#include "Resource.h"
#include "Floor.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawner.h"

int pa::Main(pa::Arguments* arguments)
{
	// Start up platform
	pa::PlatformSettings settings;
	settings.title = "Jungle Run";
	auto width = 384;
	auto height = 216;
	settings.graphics.size.set(width, height);
	settings.graphics.zoom = 4.f;

	auto platform = pa::Make::platform(arguments, settings);

	g_resource.create(platform);

	pa::Asset::load(*platform->getGraphics());

	platform->getGraphics()->getResourceManager().loadAll();
	platform->getSound()->getResourceManager().loadAll();

	// Initialise the platform
	pa::World world(platform);

	world.create<ParallaxBackground>(width, height);
	for (auto x = 0; x < width + 32; x += 16)
	{
		world.create<Floor>(g_resource.floor, x + 8, height - 16, 30);
	}
	world.create<Player>(g_resource.playerRunning, 64, height - 48);
	world.create<EnemySpawner>();

	// Process main loop
	while (true)
	{
		platform->pollEvents();
		auto& input = platform->getInput();

		if (!world.step(pa::Time(1.f / 60.f), input))
		{
			break;
		}

		platform->idle();
	}

	return 0;
}

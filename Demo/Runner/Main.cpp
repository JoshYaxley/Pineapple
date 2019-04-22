#include <Pineapple/Pineapple.h>

#include "Resource.h"

int pa::Main(pa::Arguments* arguments)
{
	// Start up platform
	pa::PlatformSettings settings;
	settings.title = "Jungle Run";
	settings.graphics.size.set(384, 216);
	settings.graphics.zoom = 2.f;

	auto platform = pa::Make::platform(arguments, settings);

	g_resource.create(platform);

	pa::Asset::load(*platform->getGraphics());

	platform->getGraphics()->getResourceManager().loadAll();
	platform->getSound()->getResourceManager().loadAll();

	// Initialise the platform
	pa::World world(platform);

	world.create<Background>(g_resource.background0);
	world.create<Background>(g_resource.background1);
	world.create<Background>(g_resource.background2);
	world.create<Background>(g_resource.background3);
	world.create<Background>(g_resource.background4);

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
#include "Level.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "Floor.h"
#include "ParallaxBackground.h"
#include "Resource.h"

Level::Level(pa::World& world)
	: pa::Object(world)
{
	world.create<ParallaxBackground>(384, 216);
	for (auto x = 0; x < 384 + 32; x += 16)
	{
		world.create<Floor>(g_resource.floor, x + 8, 216 - 16, 30);
	}
	m_player = world.create<Player>(g_resource.playerRunning, 64, 216 - 48);
	world.create<EnemySpawner>();
}

void Level::onStep(pa::Time deltaTime)
{
	for (auto&& enemy : getWorld().getChildList<Enemy>())
	{
		if (enemy->getAABB().calculateSweptAABB().intersects(m_player->getAABB().calculateSweptAABB()))
		{
			getWorld().resetNextStep<Level>();
			break;
		}
	}
}

#include "EnemySpawner.h"
#include "Resource.h"
#include "Snake.h"

EnemySpawner::EnemySpawner(pa::World& world)
	: pa::Object(world)
	, TimerHandler(world)
	, m_world(world)
{
	startTimer(pa::Time(4.f),
			   [this] {
				   m_world.create<Snake>(g_resource.snake, 400, 216 - 36, 40);
			   },
			   true);
}

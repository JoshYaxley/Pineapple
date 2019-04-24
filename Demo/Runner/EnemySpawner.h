#include "Pineapple/Engine/System/Object.h"
#include "Pineapple/Engine/System/TimerHandler.h"

struct EnemySpawner : pa::Object, pa::TimerHandler
{
private:
	pa::World& m_world;

public:
	EnemySpawner(pa::World& world);
};

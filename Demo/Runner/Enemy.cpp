#include "Enemy.h"
#include "Pineapple/Engine/System/World.h"

Enemy::Enemy(pa::World& world, int x, int y, int speed)
	: Entity(world)
	, pa::EnableChildList<Enemy>(world)
{
	setPosition(x, y);
	setVelocity(speed * -1, 0);
}

void Enemy::onStep(pa::Time deltaTime)
{
	Entity::onStep(deltaTime);

	const auto position = getPosition();
	if (position.x < -16)
	{
		destroy();
	}
}

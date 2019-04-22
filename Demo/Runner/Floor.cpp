#include "Floor.h"

Floor::Floor(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y, float speed)
	: pa::Entity(world)
{
	setPosition(x, y);
	setVelocity(speed * -1, 0);
	setSprite(texture->createSprite());
}

void Floor::onStep(pa::Time deltaTime) {
	Entity::onStep(deltaTime);

	const auto position = getPositionConst();
	if (position.x <= -8)
	{
		setPosition(position.x + 384 + 32, position.y);
	}
}

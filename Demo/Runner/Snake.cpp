#include "Snake.h"

Snake::Snake(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y, int speed) : Enemy(world, x, y, speed), m_steps(0) {
	setSprite(texture->createSprite({32, 12}));
}

void Snake::onStep(pa::Time deltaTime) {
	Enemy::onStep(deltaTime);

	const auto sprite = getSprite();
	const auto numberOfFrames = sprite->getNumberOfFrames();
	const auto stepsPerFrame = 10;
	m_steps = (m_steps + 1) % (numberOfFrames * stepsPerFrame);
	sprite->setFrame(floor(m_steps / stepsPerFrame));
}

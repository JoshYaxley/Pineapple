#include "Player.h"

Player::Player(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y)
	: pa::Entity(world)
{
	setPosition(x, y);
	setSprite(texture->createSprite({21, 33}));
	m_steps = 0;
}

void Player::onStep(pa::Time deltaTime)
{
	Entity::onStep(deltaTime);

	auto const sprite = getSprite();
	const auto numberOfFrames = sprite->getNumberOfFrames();
	const auto stepsPerFrame = 10;
	m_steps = (m_steps + 1) % (numberOfFrames * stepsPerFrame); 
	sprite->setFrame(floor(m_steps / stepsPerFrame));
}

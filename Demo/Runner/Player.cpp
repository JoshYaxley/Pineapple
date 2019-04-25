#include "Player.h"
#include "Resource.h"
#include "Enemy.h"
#include <spdlog/logger.h>

Player::Player(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y)
	: pa::Entity(world)
	, pa::InputHandler(world)
{
	setPosition(x, y);
	setSprite(texture->createSprite({21, 33}));
	m_steps = 0;
	m_state = running;
}

void Player::onStep(pa::Time deltaTime)
{
	Entity::onStep(deltaTime);

	switch (m_state)
	{
	case running:
	{
		const auto sprite = getSprite();
		const auto numberOfFrames = sprite->getNumberOfFrames();
		const auto stepsPerFrame = 10;
		m_steps = (m_steps + 1) % (numberOfFrames * stepsPerFrame);
		sprite->setFrame(floor(m_steps / stepsPerFrame));
		break;
	}
	case jumping:
	{
		const auto position = getPositionConst();
		if (position.y >= 168)
		{
			setPosition(position.x, 168);
			setVelocity(0, 0);
			setSprite(g_resource.playerRunning->createSprite({21, 33}));
			m_state = running;
			break;
		}

		const auto velocity = getVelocityConst();
		setVelocity(0, velocity.y + 1.f);
		break;
	}
	}
}

void Player::onKeyPress(pa::Key key)
{
	if (key == pa::Key::Space && m_state == running)
	{
		m_state = jumping;
		setSprite(g_resource.playerJumping->createSprite());
		setVelocity(0, -60);
	}
}

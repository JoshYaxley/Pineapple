#include "Pineapple/Engine/Prefab/Game/Entity.h"

#include "ParallaxBackground.h"
#include "Resource.h"

ParallaxBackground::ParallaxBackground(pa::World& world, Resource resource)
	: pa::Entity(world)
{
	world.create<BackgroundLayer>(resource.background0)->setPosition(m_position.x, m_position.y);
	world.create<BackgroundLayer>(resource.background1)->setPosition(m_position.x, m_position.y);
	world.create<BackgroundLayer>(resource.background2)->setPosition(m_position.x, m_position.y);
	world.create<BackgroundLayer>(resource.background3)->setPosition(m_position.x, m_position.y);
	world.create<BackgroundLayer>(resource.background4)->setPosition(m_position.x, m_position.y);
}

BackgroundLayer::BackgroundLayer(pa::World& world, std::shared_ptr<pa::Texture> texture)
	: pa::Entity(world)
{
	setSprite(texture->createSprite());
}

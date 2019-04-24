#include "Pineapple/Engine/Prefab/Game/Entity.h"

#include "ParallaxBackground.h"
#include "Resource.h"

ParallaxBackground::ParallaxBackground(pa::World& world, int width, int height)
	: pa::Object(world)
{
	for (auto offset = 0; offset <= 1; offset++)
	{
		world.create<BackgroundLayer>(g_resource.background0, 500, width, height, offset, 0);
		world.create<BackgroundLayer>(g_resource.background1, 400, width, height, offset, 6);
		world.create<BackgroundLayer>(g_resource.background2, 300, width, height, offset, 12);
		world.create<BackgroundLayer>(g_resource.background3, 200, width, height, offset, 18);
		world.create<BackgroundLayer>(g_resource.background4, 100, width, height, offset, 30);
	}
}

BackgroundLayer::BackgroundLayer(pa::World& world, std::shared_ptr<pa::Texture> texture, int depth, int width, int height, int offset, float speed)
	: pa::Entity(world)
{
	m_width = width;
	m_offset = offset;

	const float centreX = width * (m_offset + 0.5);
	const float centreY = height * 0.5;

	setSprite(texture->createSprite());
	getSprite()->setPriority(depth * -1);
	setPosition(centreX, centreY);

	setVelocity(speed * -1, 0);
}

void BackgroundLayer::onStep(pa::Time deltaTime) {
	Entity::onStep(deltaTime);

	const auto position = getPositionConst();
	if (position.x <= m_width * (m_offset - 0.5))
	{
		setPosition(position.x + m_width, position.y);
	}
}

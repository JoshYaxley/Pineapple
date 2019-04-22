#include "Pineapple/Engine/Prefab/Game/Entity.h"

struct Background : public pa::Entity
{
	Background(pa::World& world, std::shared_ptr<pa::Texture> texture)
		: pa::Entity(world)
	{
		setSprite(texture->createSprite());
	}
};

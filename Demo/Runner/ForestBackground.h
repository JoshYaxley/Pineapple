#include "Pineapple/Engine/Prefab/Game/Entity.h"
#include "Resource.h"

struct ParallaxBackground : public pa::Entity
{
public:
	ParallaxBackground(pa::World& world, Resource resource);
};

struct BackgroundLayer : public pa::Entity
{
public:
	BackgroundLayer(pa::World& world, std::shared_ptr<pa::Texture> texture);
};
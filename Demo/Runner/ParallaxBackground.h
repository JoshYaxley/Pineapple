#include "Pineapple/Engine/Prefab/Game/Entity.h"
#include "Resource.h"

struct ParallaxBackground : pa::Object
{
public:
	ParallaxBackground(pa::World& world, int width, int height);
};

struct BackgroundLayer : pa::Entity
{
private:
	int m_width;
	int m_offset;

public:
	BackgroundLayer(pa::World& world, std::shared_ptr<pa::Texture> texture, int depth, int width, int height, int offset, float speed);
	void onStep(pa::Time deltaTime) override;
};
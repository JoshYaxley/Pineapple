#include "Pineapple/Engine/Prefab/Game/Entity.h"

struct Floor : public pa::Entity
{
public:
	Floor(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y, float speed);
	void onStep(pa::Time deltaTime) override;
};
#include "Pineapple/Engine/Prefab/Game/Entity.h"

struct Enemy : public pa::Entity
{
public:
	Enemy(pa::World& world, int x, int y, int speed);
	void onStep(pa::Time deltaTime) override;
};

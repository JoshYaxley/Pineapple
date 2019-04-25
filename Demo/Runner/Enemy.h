#include "Pineapple/Engine/Prefab/Game/Entity.h"
#include "Pineapple/Engine/System/EnableChildList.h"

struct Enemy : public pa::Entity, private pa::EnableChildList<Enemy>
{
public:
	Enemy(pa::World& world, int x, int y, int speed);
	void onStep(pa::Time deltaTime) override;
};

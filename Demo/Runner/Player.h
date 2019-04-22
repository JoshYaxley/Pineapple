#include "Pineapple/Engine/Prefab/Game/Entity.h"

struct Player : public pa::Entity
{
private:
	int m_steps;

public:
	Player(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y);
	void onStep(pa::Time deltaTime) override;
};
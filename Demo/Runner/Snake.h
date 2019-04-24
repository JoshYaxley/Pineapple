#include "Enemy.h"

struct Snake : Enemy
{
private:
	int m_steps;

public:
	Snake(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y, int speed);
	void onStep(pa::Time deltaTime) override;
};

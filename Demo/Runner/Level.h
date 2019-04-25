#include <Pineapple/Pineapple.h>
#include "Player.h"

struct Level : public pa::Object
{
private:
	std::shared_ptr<Player> m_player;

public:
	Level(pa::World& world);
	void onStep(pa::Time deltaTime) override;
};

#include "Pineapple/Engine/Prefab/Game/Entity.h"
#include "Pineapple/Engine/System/InputHandler.h"

enum playerState
{
	running,
	jumping
};

struct Player : public pa::Entity, public pa::InputHandler
{
private:
	playerState m_state;
	int m_steps;

public:
	Player(pa::World& world, std::shared_ptr<pa::Texture> texture, int x, int y);
	void onStep(pa::Time deltaTime) override;
	void onKeyPress(pa::Key key) override;
};

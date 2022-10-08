#include <stdbool.h>

#include "Framework.h"
#include "configs/ConfigsHolder.h"
#include "fabrics/EntitiesFabric.h"
#include "managers/EntityManager.h"
#include "managers/SystemManager.h"
#include "utilities//ScreenResolution.h"
#include "systems/DeflectSystem.h"

class Arcanoid : public Framework {

public:
	ScreenResolution* screenResolution;
	SystemManager* systemManager;
	EntityManager* entityManager;
	bool initFlag = true;
	bool releaseBallFlag = true;
	
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		/*std::cout << "Input screen width" << std::endl;
		std::cin >> width;
		std::cout << "Input screen height" << std::endl;
		std::cin >> height;*/
		
		width = ScreenResolution::WIDTH;
		height = ScreenResolution::HEIGHT;
		fullscreen = false;
	}

	virtual bool Init() {
		//todo refactor
		if(initFlag)
		{
			config::ConfigsHolder* configs_holder = new config::ConfigsHolder();
			systemManager = new SystemManager();
			entityManager = EntitiesFabric::makeEntityManager(configs_holder, systemManager);
			systemManager->getDeflectSystem().setSystemManager(systemManager);
		}
		initFlag = false;
		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		systemManager->getMoveBallSystem().process();
		systemManager->getDeflectSystem().process();
		drawTestBackground();
		systemManager->getRenderSystem().process();

		/*auto whiteTileDeflectNode = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
	entityManager->getWhiteTile().getRenderNodeCoord(), entityManager->getBall().getBallSpeed(),
	entityManager->getBall().getSize(), entityManager->getWhiteTile().getSize(),
	DeflectNode::Target::Tile, entityManager->getBall().getBaseSpeed());

		systemManager->getDeflectSystem().addNode(whiteTileDeflectNode);*/
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		systemManager->getMouseTrackSystem().process(entityManager->getBall().get_mouse_track_node(), x, y);
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if(button == FRMouseButton::LEFT && isReleased && releaseBallFlag)
		{	//todo refactor
			Ball& ball = entityManager->getBall();
			systemManager->getConstantXMoveSystem().removeNode(ball.get_constant_x_move_node());
			systemManager->getreleaseBallSystem().process();
			systemManager->getreleaseBallSystem().removeNodes();
			systemManager->getMoveBallSystem().addNode(ball.get_move_ball_node());
			releaseBallFlag = false;
		}
	}

	virtual void onKeyPressed(FRKey k) {
		systemManager->getConstantXMoveSystem().process(k);

		//todo align constantXMoveSystem with others by crating last pressek key system and create system manager
	}

	virtual void onKeyReleased(FRKey k) {
	}

	const char* GetTitle() override
	{
		return "Arcanoid";
	}
};

int main(int argc, char* argv[])
{
	return run(new Arcanoid);
}

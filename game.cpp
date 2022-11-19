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
	std::shared_ptr<SystemManager> systemManager;
	std::shared_ptr<EntityManager> entityManager;
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
			systemManager = EntitiesFabric::systemManager();
			entityManager = std::make_shared<EntityManager>(EntitiesFabric::makeEntityManager(configs_holder, systemManager));
		}
		initFlag = false;
		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		systemManager->getMoveBallSystem()->process();
		systemManager->getDeflectSystem()->process();
		drawTestBackground();
		systemManager->getRenderSystem()->process();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		systemManager->getMouseTrackSystem()->process(Coord(x, y));
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if(button == FRMouseButton::LEFT && isReleased && releaseBallFlag)
		{	//todo refactor
			Ball& ball = entityManager->getBall();
			systemManager->getConstantXMoveSystem()->removeNode(ball.getUUID());
			systemManager->getreleaseBallSystem()->process();
			systemManager->getreleaseBallSystem()->removeNode(ball.getUUID());
			systemManager->getMoveBallSystem()->addNode(ball.getUUID(), ball.getMoveBallNode());
			releaseBallFlag = false;
		}
	}

	virtual void onKeyPressed(FRKey k) {
		systemManager->getPressedKeyTrackSystem()->process(k);
		systemManager->getConstantXMoveSystem()->process();

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

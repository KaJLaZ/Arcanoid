#include "Framework.h"
#include "configs/ConfigsHolder.h"
#include "fabrics/EntitiesFabric.h"
#include "managers/EntityManager.h"
#include "managers/SystemManager.h"
#include "utilities//ScreenResolution.h"
#include "systems/DeflectSystem.h"
#include "utilities/Crutch.h"

class Arcanoid : public Framework {

public:
	ScreenResolution* screenResolution;
	SystemManager* systemManager;
	EntityManager* entityManager;
	
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
		systemManager = new SystemManager();
		entityManager = EntitiesFabric::makeEntityManager(systemManager);
		systemManager->getDeflectSystem().setSystemManager(systemManager);
		//systemManager->getTileHealthSystem().setEntityManager(entityManager);
		systemManager->getTileHealthSystem().setSysteManager(systemManager);
		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		systemManager->getMoveBallSystem().process();
		systemManager->getDeflectSystem().process();
		drawTestBackground();
		systemManager->getRenderSystem().process();
		
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		systemManager->getMouseTrackSystem().process(entityManager->getBall(), x, y);
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if(button == FRMouseButton::LEFT && isReleased)
		{	//todo fix speed boost bug
			Crutch::afterBallRelleaseInitialization(systemManager, entityManager);
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

void createBorders(SystemManager* systemManager, EntityManager* entityManager)
{
	systemManager->getConstantXMoveSystem().removeNode(entityManager->getBall());
	systemManager->getreleaseBallSystem().process();
	systemManager->getreleaseBallSystem().removeNodes();
	systemManager->getMoveBallSystem().addNode(entityManager->getBall());

	auto titleHealthNode = new TileHealthNode(entityManager->getWhiteTile().getRenderNodeCoord(),
		new int(1), &entityManager->getWhiteTile());
	auto whiteTileDeflectNode = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
		entityManager->getWhiteTile().getRenderNodeCoord(), entityManager->getBall().getBallSpeed(),
		entityManager->getBall().getSize(), entityManager->getWhiteTile().getSize(),
		DeflectNode::Target::Tile, entityManager->getBall().getBaseSpeed());
	auto platformDeflectNode = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
		entityManager->getPlatform().getRenderNodeCoord(), entityManager->getBall().getBallSpeed(),
	entityManager->getBall().getSize(), entityManager->getPlatform().getSize(),
	DeflectNode::Target::Platform, entityManager->getBall().getBaseSpeed());
			
	auto leftBorder = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
		new Coord(0, 0), entityManager->getBall().getBallSpeed(),
	entityManager->getBall().getSize(), Size(3,ScreenResolution::HEIGHT),
	DeflectNode::Target::Border, entityManager->getBall().getBaseSpeed());

	systemManager->getDeflectSystem().addNode(whiteTileDeflectNode);
	systemManager->getDeflectSystem().addNode(platformDeflectNode);
	systemManager->getDeflectSystem().addNode(leftBorder);
}

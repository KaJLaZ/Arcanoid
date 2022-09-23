#pragma once

#include "../managers/EntityManager.h"

class Crutch
{
public:
        static void afterBallRelleaseInitialization(SystemManager* systemManager, EntityManager* entityManager)
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

        auto topBorder = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
            new Coord(4, 0), entityManager->getBall().getBallSpeed(),
        entityManager->getBall().getSize(), Size(ScreenResolution::WIDTH,3),
        DeflectNode::Target::Border, entityManager->getBall().getBaseSpeed());

        auto rightBorder = new DeflectNode(entityManager->getBall().getReleaseBallCoord(),
            new Coord(ScreenResolution::WIDTH - 4, 4), entityManager->getBall().getBallSpeed(),
        entityManager->getBall().getSize(), Size(3,ScreenResolution::HEIGHT),
        DeflectNode::Target::Border, entityManager->getBall().getBaseSpeed());
        
        systemManager->getDeflectSystem().addNode(whiteTileDeflectNode);
        systemManager->getDeflectSystem().addNode(platformDeflectNode);
        systemManager->getDeflectSystem().addNode(leftBorder);
        systemManager->getDeflectSystem().addNode(topBorder);
        systemManager->getDeflectSystem().addNode(rightBorder);
    }
    
};

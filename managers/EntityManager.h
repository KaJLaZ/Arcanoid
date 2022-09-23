#pragma once
#include "SystemManager.h"
#include "../configs/ConfigResolutionAdjuster.h"
#include "../configs/ConfigsHolder.h"
#include "../entities/Platform.h"

class EntityManager
{
public:
    EntityManager(config::ConfigsHolder configHolder, Platform* platform, Ball* ball, WhiteTile* white_tile)
        : configHolder(std::move(configHolder)),
        platform(std::move(platform)),
        ball(std::move(ball)),
        whiteTile(std::move(white_tile)){};

    void removeWhiteTile(SystemManager* systemManager) {
        systemManager->getRenderSystem().removeNode(*whiteTile);
        auto node = new DeflectNode (ball->getMoveBallCoord(), whiteTile->getRenderNodeCoord(), ball->getBallSpeed(), ball->getSize(),
            whiteTile->getSize(), DeflectNode::Target::Tile, ball->getBaseSpeed());
        delete whiteTile;
    }

    Platform& getPlatform()
    {
        return *platform;
    }

    Ball& getBall()
    {
        return *ball;
    }

    WhiteTile& getWhiteTile()
    {
        return *whiteTile;
    }

private:
    config::ConfigsHolder configHolder;
    Platform* platform;
    Ball* ball;
    WhiteTile* whiteTile;
};

//TODO think about adding new service that will be correct config by resolution 

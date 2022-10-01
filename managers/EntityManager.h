#pragma once
#include "SystemManager.h"
#include "../configs/ConfigsHolder.h"
#include "../entities/Platform.h"

class EntityManager
{
public:
    EntityManager(Platform* platform, Ball* ball, WhiteTile* white_tile)
        : platform(std::move(platform)),
        ball(std::move(ball)),
        whiteTile(std::move(white_tile)){}

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
    Platform* platform;
    Ball* ball;
    WhiteTile* whiteTile;
};

//TODO think about adding new service that will be correct config by resolution 

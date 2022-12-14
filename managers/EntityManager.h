#pragma once
#include "SystemManager.h"
#include "../entities/Platform.h"
#include "../entities/UserInputTracker.h"

class EntityManager
{
public:
    EntityManager(Platform platform, Ball ball, WhiteTile whiteTile, UserInputTracker userInputTracker,
        WhiteTile leftBorderTile, WhiteTile topBorderTile, WhiteTile rightBorderTile)
        : platform(std::move(platform)),
        ball(std::move(ball)),
        whiteTile(std::move(whiteTile)),
        userInputTracker(std::move(userInputTracker)),
        leftBorderTile(std::move(leftBorderTile)),
        topBorderTile(std::move(topBorderTile)),
        rightBorderTile(std::move(rightBorderTile)){}

    Platform& getPlatform()
    {
        return platform;
    }

    Ball& getBall()
    {
        return ball;
    }

    WhiteTile& getWhiteTile()
    {
        return whiteTile;
    }

private:
    
    Platform platform;
    Ball ball;
    WhiteTile whiteTile;
    UserInputTracker userInputTracker;
    WhiteTile leftBorderTile;
    WhiteTile topBorderTile;
    WhiteTile rightBorderTile;
};

//TODO think about adding new service that will be correct config by resolution 

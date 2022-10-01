#pragma once
#include "../components/Coord.h"
#include "../components/Speed.h"

class ReleaseBallNode
{
public:
    ReleaseBallNode(Coord* ballCoord, Coord* mouseCoord, Speed* ballSpeed, double baseSpeed)
        : ballCoord(ballCoord),
          mouseCoord(mouseCoord),
          ballSpeed(ballSpeed),
          baseSpeed(baseSpeed){}

    Coord* getReleaseBallCoord()
    {
        return ballCoord;
    }

    Coord* getMouseCoord()
    {
        return mouseCoord;
    }

    double getBaseSpeed()
    {
        return baseSpeed;
    }

    void setBallSpeed(double x, double y)
    {
        this->ballSpeed->setX(x);
        this->ballSpeed->setY(y);
    }

private:
    Coord* ballCoord;
    Coord* mouseCoord;
    Speed* ballSpeed;
    double baseSpeed;
};

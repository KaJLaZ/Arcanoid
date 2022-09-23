#pragma once
#include "../components/Coord.h"
#include "../components/Speed.h"

class ReleaseBallNode
{
public:
    ReleaseBallNode(Coord* ballCoord, Coord* mouseCoord, Speed* speed, double baseSpeed)
        : ballCoord(ballCoord),
          mouseCoord(mouseCoord),
          speed(speed),
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

    void setSpeed(double x, double y)
    {
        this->speed->setX(x);
        this->speed->setY(y);
    }

private:
    Coord* ballCoord;
    Coord* mouseCoord;
    Speed* speed;
    double baseSpeed;
};

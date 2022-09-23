#pragma once
#include "../components/Coord.h"
#include "../components/Speed.h"

class MoveBallNode
{
public:
    MoveBallNode(Coord* ballCoord, Speed* speed)
        : ballCoord(ballCoord),
          speed(speed){}

    Coord* getMoveBallCoord()
    {
        return ballCoord;
    }

    Speed* getBallSpeed()
    {
        return speed;
    }

    void shiftBallCoord(double x, double y)
    {
        this->ballCoord->setX(ballCoord->getX() + x);
        this->ballCoord->setY(ballCoord->getY() + y);
    }

    void shiftBallSpeed(double x, double y)
    {
        this->speed->setX(speed->getX() + x);
        this->speed->setY(speed->getY() + y);
    }

private:
    Coord* ballCoord;
    Speed* speed;
};

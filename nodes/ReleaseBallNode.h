#pragma once
#include "../components/Coord.h"
#include "../components/Speed.h"

class ReleaseBallNode
{
public:
    ReleaseBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<Speed> ballSpeed, std::shared_ptr<double> baseSpeed)
        : ballCoord(std::move(ballCoord)),
          mouseCoord(std::move(mouseCoord)),
          ballSpeed(std::move(ballSpeed)),
          baseSpeed(std::move(baseSpeed)){}

    Coord getReleaseBallCoord()
    {
        return *ballCoord;
    }

    Coord getMouseCoord()
    {
        return *mouseCoord;
    }

    double getBaseSpeed()
    {
        return *baseSpeed;
    }

    void setBallSpeed(double x, double y)
    {
        this->ballSpeed->setX(x);
        this->ballSpeed->setY(y);
    }

private:
    std::shared_ptr<Coord> ballCoord;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<Speed> ballSpeed;
    std::shared_ptr<double> baseSpeed;
};

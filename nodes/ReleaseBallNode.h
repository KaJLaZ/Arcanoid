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

    std::shared_ptr<Coord> getReleaseBallCoord()
    {
        return ballCoord;
    }

    std::shared_ptr<Coord> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<double> getBaseSpeed()
    {
        return baseSpeed;
    }

    void setBallSpeed(double x, double y)
    {
        this->ballSpeed->setX(x);
        this->ballSpeed->setY(y);
        //*ballSpeed = Speed(x, y);
    }

private:
    std::shared_ptr<Coord> ballCoord;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<Speed> ballSpeed;
    std::shared_ptr<double> baseSpeed;
};

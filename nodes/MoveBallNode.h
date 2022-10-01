#pragma once
#include "../components/Coord.h"
#include "../components/Speed.h"

class MoveBallNode
{
public:
    MoveBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Speed> speed)
        : ballCoord(std::move(ballCoord)),
          speed(std::move(speed)){}

    std::shared_ptr<Coord> getCoord()
    {
        return ballCoord;
    }

    std::shared_ptr<Speed> getSpeed()
    {
        return speed;
    }

    void shiftCoord(double x, double y)
    {
        this->ballCoord->setX(ballCoord->getX() + x);
        this->ballCoord->setY(ballCoord->getY() + y);
    }

    void shiftSpeed(double x, double y)
    {
        this->speed->setX(speed->getX() + x);
        this->speed->setY(speed->getY() + y);
    }

private:
    std::shared_ptr<Coord> ballCoord;
    std::shared_ptr<Speed> speed;
};

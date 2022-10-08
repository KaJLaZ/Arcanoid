#pragma once
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../components/Speed.h"

class DeflectNode
{
public:
    DeflectNode(std::shared_ptr<Coord> ballCord, std::shared_ptr<Coord> targetCord, std::shared_ptr<Speed> ballSpeed,
        Size ballSize, Size targetSize):
        ballCord(std::move(ballCord)),
        targetCord(std::move(targetCord)),
        ballSpeed(std::move(ballSpeed)),
        ballSize(ballSize),
        targetSize(targetSize){}

    Coord getBallCord()
    {
        return *ballCord;
    }

    Coord getDeflectTargetCord()
    {
        return *targetCord;
    }

    Speed getBallSpeed()
    {
        return *ballSpeed;
    }

    void setBallSpeed(double x, double y)
    {
        this->ballSpeed->setX(x);
        this->ballSpeed->setY(y);
    }

    Size getBallSize()
    {
        return ballSize;
    }

    Size getTargetSize()
    {
        return targetSize;
    }

    friend bool operator==(const DeflectNode& lhs, const DeflectNode& rhs)
    {
        return std::tie(lhs.ballCord, lhs.targetCord, lhs.ballSpeed, lhs.ballSize, lhs.targetSize) == std::tie(
            rhs.ballCord, rhs.targetCord, rhs.ballSpeed, rhs.ballSize, rhs.targetSize);
    }

private:
    std::shared_ptr<Coord> ballCord;
    std::shared_ptr<Coord> targetCord;
    std::shared_ptr<Speed> ballSpeed;
    Size ballSize;
    Size targetSize;
};

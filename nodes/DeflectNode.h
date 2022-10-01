#pragma once
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../components/Speed.h"

class DeflectNode
{
public:
    enum class Target
    {
        Tile, Platform, Border
    };

    DeflectNode(std::shared_ptr<Coord> ballCord, std::shared_ptr<Coord> targetCord, std::shared_ptr<Speed> ballSpeed,
        Size ballSize, Size targetSize, Target target, std::shared_ptr<double> baseSpeed):
        ballCord(std::move(ballCord)),
        targetCord(std::move(targetCord)),
        ballSpeed(std::move(ballSpeed)),
        ballSize(ballSize),
        targetSize(targetSize),
        target(target),
        baseSpeed(std::move(baseSpeed)){}

    std::shared_ptr<Coord> getBallCord()
    {
        return ballCord;
    }

    std::shared_ptr<Coord> getDeflectTargetCord()
    {
        return targetCord;
    }

    std::shared_ptr<Speed> getBallSpeed()
    {
        return ballSpeed;
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

    Target getTarget()
    {
        return target;
    }

    double getBaseSpeed()
    {
        return *baseSpeed;
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
    Target target;
    std::shared_ptr<double> baseSpeed;
};

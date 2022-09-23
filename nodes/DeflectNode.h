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
    
    DeflectNode(Coord* ballCord, Coord* targetCord,Speed* ballSpeed, Size ballSize,
        Size targetSize, Target target, double baseSpeed)
        : ballCord(ballCord),
          targetCord(targetCord),
          ballSpeed(ballSpeed),
          ballSize(ballSize),
          targetSize(targetSize),
          target(target),
          baseSpeed(baseSpeed){}

    Coord* getBallCord()
    {
        return ballCord;
    }

    Coord* getDeflectTargetCord()
    {
        return targetCord;
    }

    Speed* getBallSpeed()
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
        return baseSpeed;
    }

    friend bool operator==(const DeflectNode& lhs, const DeflectNode& rhs)
    {
        return std::tie(lhs.ballCord, lhs.targetCord, lhs.ballSpeed, lhs.ballSize, lhs.targetSize) == std::tie(
            rhs.ballCord, rhs.targetCord, rhs.ballSpeed, rhs.ballSize, rhs.targetSize);
    }

private:
    Coord* ballCord;
    Coord* targetCord;
    Speed* ballSpeed;
    Size ballSize;
    Size targetSize;
    Target target;
    double baseSpeed;
};

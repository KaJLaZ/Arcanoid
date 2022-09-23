#pragma once
#include "../components/Coord.h"

class ConstantXMoveNode
{
public:
    explicit ConstantXMoveNode(Coord* coord, int moveDistance)
        : coord(coord), moveDistance(moveDistance){}

    Coord* getConstXMoveCoord()
    {
        return coord;
    }

    void shiftCoord(double x, double y)
    {
        this->coord->setX(coord->getX() + x);
        this->coord->setY(coord->getY() + y);
    }

    int getMoveDistance()
    {
        return moveDistance;
    }

    friend bool operator==(const ConstantXMoveNode& lhs, const ConstantXMoveNode& rhs)
    {
        return std::tie(lhs.coord, lhs.moveDistance) == std::tie(rhs.coord, rhs.moveDistance);
    }

private:
    Coord* coord;
    int moveDistance;
};

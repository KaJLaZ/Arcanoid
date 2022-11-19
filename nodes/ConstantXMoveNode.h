#pragma once

#include "../components/Coord.h"

class ConstantXMoveNode
{
public:
    ConstantXMoveNode(std::shared_ptr<Coord> coord, std::shared_ptr<int> moveDistance, std::shared_ptr<FRKey> pressedKey)
        : coord(std::move(coord)), moveDistance(std::move(moveDistance)), pressedKey(std::move(pressedKey)){}

    Coord getCoord()
    {
        return *coord;
    }

    void shiftCoord(double x, double y)
    {
        this->coord->setX(coord->getX() + x);
        this->coord->setY(coord->getY() + y);
    }

    int getMoveDistance()
    {
        return *moveDistance;
    }

    FRKey getpressedKey()
    {
        return *pressedKey;
    }
    
private:
    std::shared_ptr<Coord> coord;
    std::shared_ptr<int> moveDistance;
    std::shared_ptr<FRKey> pressedKey;
};

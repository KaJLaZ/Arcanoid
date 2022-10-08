#pragma once

#include "../components/Coord.h"

class MouseTrackNode
{
public:
    MouseTrackNode(std::shared_ptr<Coord> mouseCoord) : mouseCoord(std::move(mouseCoord)){}

    Coord getCoord()
    {
        return *mouseCoord;
    }

    void setMouseCoord(double x, double y)
    {
        this->mouseCoord->setX(x);
        this->mouseCoord->setY(y);
    }

private:
    std::shared_ptr<Coord> mouseCoord;
};

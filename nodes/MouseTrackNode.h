#pragma once

#include "../components/Coord.h"

class MouseTrackNode
{
public:
    explicit MouseTrackNode(std::shared_ptr<Coord> mouseCoord) : mouseCoord(std::move(mouseCoord)){}

    std::shared_ptr<Coord> getCoord()
    {
        return mouseCoord;
    }
    //todo remove moteableness
    void setMouseCoord(double x, double y)
    {
        this->mouseCoord->setX(x);
        this->mouseCoord->setY(y);
    }

private:
    std::shared_ptr<Coord> mouseCoord;
};

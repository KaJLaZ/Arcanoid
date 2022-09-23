#pragma once

#include "../components/Coord.h"

class MouseTrackNode
{
public:
    explicit MouseTrackNode(Coord* mouseCoord) : mouseCoord(mouseCoord){}

    Coord* getMouseCoord()
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
    Coord* mouseCoord;
};

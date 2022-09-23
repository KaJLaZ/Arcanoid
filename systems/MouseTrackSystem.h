#pragma once

#include "../nodes/MouseTrackNode.h"

class MouseTrackSystem
{
public:
    void process(MouseTrackNode& trackNode, double x, double y)
    {
        trackNode.setMouseCoord(x, y);
    }
};

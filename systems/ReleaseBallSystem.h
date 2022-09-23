#pragma once

#include "../nodes/ReleaseBallNode.h"
#include "cmath"

class ReleaseBallSystem
{
public:
    void addNode(ReleaseBallNode& node)
    {
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (ReleaseBallNode& node)
        {
            double ballCoordX = node.getReleaseBallCoord()->getX();
            double ballCoordY = node.getReleaseBallCoord()->getY();
        
            double difX = node.getMouseCoord()->getX() - ballCoordX;
            double difY = node.getMouseCoord()->getY() - ballCoordY;

            double signX = difX > 0 ? 1: -1;
            double signY = difY > 0 ? 1: -1;

            double percX = fabs(difX) / node.getBaseSpeed();
            double percY = fabs(difY) / node.getBaseSpeed();

            double perccX = percX * 100/(percX + percY);
            double perccY = percY * 100/(percX + percY);

            double xSpeed = perccX * node.getBaseSpeed() / 100 * signX;
            double ySpeed = perccY * node.getBaseSpeed() / 100 * signY;
            
            node.setSpeed(xSpeed, ySpeed);
        });
    }

    void removeNodes()
    {
        nodes.clear();
    }

private:
    std::vector<ReleaseBallNode> nodes;
};

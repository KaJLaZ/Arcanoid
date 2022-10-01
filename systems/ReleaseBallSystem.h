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
            double difX = node.getMouseCoord()->getX() - node.getReleaseBallCoord()->getX();
            double difY = node.getMouseCoord()->getY() - node.getReleaseBallCoord()->getY();

            double absSum = fabs(difX) + fabs(difY);
            
            double propX = difX / absSum;
            double propY = difY / absSum;

            node.setBallSpeed(node.getBaseSpeed() * propX, node.getBaseSpeed() * propY);
        });
    }

    void removeNodes()
    {
        nodes.clear();
    }

private:
    std::vector<ReleaseBallNode> nodes;
};

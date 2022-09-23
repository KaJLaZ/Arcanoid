#pragma once

#include <algorithm>
#include <vector>
#include "../nodes/MoveBallNode.h"

class MoveBallSystem
{
public:
    void addNode(MoveBallNode& node)
    {
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::for_each(nodes.begin(), nodes.end(),[] (MoveBallNode& node)
        {
            node.shiftBallCoord(node.getBallSpeed()->getX(), node.getBallSpeed()->getY());
        });
    }
    
private:
    std::vector<MoveBallNode> nodes;
};

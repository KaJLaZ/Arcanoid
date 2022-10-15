#pragma once

#include "../nodes/ReleaseBallNode.h"
#include "cmath"

class ReleaseBallSystem
{
public:
    void addNode(std::string&& uuid, ReleaseBallNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes, [](std::pair<const std::string, ReleaseBallNode> pair)
        {
            double difX = pair.second.getMouseCoord().getX() - pair.second.getReleaseBallCoord().getX();
            double difY = pair.second.getMouseCoord().getY() - pair.second.getReleaseBallCoord().getY();

            double absSum = fabs(difX) + fabs(difY);
            
            double propX = difX / absSum;
            double propY = difY / absSum;

            pair.second.setBallSpeed(pair.second.getBaseSpeed() * propX, pair.second.getBaseSpeed() * propY);
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, ReleaseBallNode> nodes;
};

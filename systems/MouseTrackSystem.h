#pragma once

#include "../nodes/MouseTrackNode.h"

class MouseTrackSystem
{
public:
    void addNode(std::string&& uuid, MouseTrackNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process(double x, double y)
    {
        std::ranges::for_each(nodes, [&](std::pair<const std::string, MouseTrackNode>& pair)
        {
            pair.second.setMouseCoord(x, y);
        });
    }

private:
    std::unordered_map<std::string, MouseTrackNode> nodes;
};

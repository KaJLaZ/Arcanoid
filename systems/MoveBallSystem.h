#pragma once

#include <algorithm>
#include "../nodes/MoveBallNode.h"

class MoveBallSystem : System<MoveBallNode>
{
public:
    MoveBallSystem(std::unordered_map<std::string, MoveBallNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, MoveBallNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, MoveBallNode>& pair)
        {
            pair.second.shiftCoord(pair.second.getSpeed().getX(), pair.second.getSpeed().getY());
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, MoveBallNode> nodes;
};

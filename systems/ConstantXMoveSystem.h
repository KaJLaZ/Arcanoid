#pragma once

#include "System.h"
#include "../nodes/ConstantXMoveNode.h"

class ConstantXMoveSystem : System<ConstantXMoveNode>
{
public:
    ConstantXMoveSystem(std::unordered_map<std::string, ConstantXMoveNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, ConstantXMoveNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, ConstantXMoveNode>& pair)
        {
            switch(pair.second.getpressedKey())
            {
            case FRKey::LEFT:
                pair.second.shiftCoord(-pair.second.getMoveDistance(), 0);
                break;
            case FRKey::RIGHT:
                pair.second.shiftCoord(pair.second.getMoveDistance(), 0);
                break;
            }
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, ConstantXMoveNode> nodes;
};

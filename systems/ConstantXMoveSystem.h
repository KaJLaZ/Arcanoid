#pragma once

#include "../nodes/ConstantXMoveNode.h"

class ConstantXMoveSystem
{
public:
    void addNode(std::string&& uuid, ConstantXMoveNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process(FRKey key)
    {
        std::ranges::for_each(nodes,[key] (std::pair<const std::string, ConstantXMoveNode>& pair)
        {
            switch(key)
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

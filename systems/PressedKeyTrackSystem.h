#pragma once

#include <algorithm>
#include <unordered_map>

#include "InputTrackSystem.h"
#include "System.h"
#include "../nodes/PressedKeyTrackNode.h"

class PressedKeyTrackSystem : InputTrackSystem<PressedKeyTrackNode, FRKey>
{
public:
    PressedKeyTrackSystem(std::unordered_map<std::string, PressedKeyTrackNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, PressedKeyTrackNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process(FRKey key)
    {
        std::ranges::for_each(nodes, [&](std::pair<const std::string, PressedKeyTrackNode>& pair)
        {
            pair.second.setPressedKey(key);
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, PressedKeyTrackNode> nodes;
};

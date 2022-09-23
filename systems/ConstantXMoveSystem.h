#pragma once

#include "../Framework.h"
#include "../nodes/ConstantXMoveNode.h"

class ConstantXMoveSystem
{
public:
    void addNode(ConstantXMoveNode& node)
    {
        nodes.emplace_back(node);
    }
    
    void process(FRKey key)
    {
        std::for_each(nodes.begin(), nodes.end(),[key] (ConstantXMoveNode& node)
        {
            switch(key)
            {
                case FRKey::LEFT:
                    node.shiftCoord(-node.getMoveDistance(), 0);
                break;
                case FRKey::RIGHT:
                    node.shiftCoord(node.getMoveDistance(), 0);
                break;
            }
        });
    }

    void removeNode(ConstantXMoveNode& node)
    {
        nodes.erase(std::ranges::remove(nodes, node).begin(), nodes.end());
    }
    
private:
    std::vector<ConstantXMoveNode> nodes;
};

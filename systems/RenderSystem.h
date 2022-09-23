#pragma once
#include <algorithm>
#include <vector>
#include "../nodes/RenderNode.h"

class RenderSystem
{
public:
    void addNode(RenderNode& node)
    {
        setSpriteSize(node.getSprite(), node.getSize().getWeigth(), node.getSize().getHeigth());
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::for_each(nodes.begin(), nodes.end(),[] (RenderNode& node)
        {
            drawSprite(node.getSprite(), std::round(node.getRenderNodeCoord()->getX()), std::round(node.getRenderNodeCoord()->getY()));
        });
    }
    
    void removeNode(RenderNode& node)
    {
        nodes.erase(std::ranges::remove(nodes, node).begin(), nodes.end());
    }
    
private:
    std::vector<RenderNode> nodes;
};

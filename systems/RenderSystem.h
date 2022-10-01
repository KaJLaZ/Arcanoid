#pragma once
#include <algorithm>
#include <vector>
#include "../nodes/RenderNode.h"

class RenderSystem
{
public:
    void addNode(RenderNode& node)
    {
        setSpriteSize(&*node.getSprite(), node.getSize().getWidth(), node.getSize().getHeigth());
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::for_each(nodes.begin(), nodes.end(),[] (RenderNode& node)
        {
            drawSprite(&*node.getSprite(), std::round(node.getCoord()->getX()), std::round(node.getCoord()->getY()));
        });
    }
    
    void removeNode(RenderNode& node)
    {
        nodes.erase(std::ranges::remove(nodes, node).begin(), nodes.end());
    }
    
private:
    std::vector<RenderNode> nodes;
};

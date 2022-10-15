#pragma once
#include <algorithm>
#include "../nodes/RenderNode.h"

class RenderSystem
{
public:
    void addNode(std::string&& uuid, RenderNode& node)
    {
        setSpriteSize(&*node.getSprite(), node.getSize().getWidth(), node.getSize().getHeigth());
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, RenderNode> pair)
        {
            drawSprite(&*pair.second.getSprite(),
                       std::round(pair.second.getCoord().getX()), std::round(pair.second.getCoord().getY()));
        });
    }
    
    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, RenderNode> nodes;
};

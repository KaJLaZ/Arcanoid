#pragma once

#include "../nodes/RenderNode.h"
#include "../nodes/DeflectNode.h"

class WhiteTile
{
public:
    explicit WhiteTile(std::string uuid, RenderNode renderNode, DeflectNode deflectNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          deflectNode(std::move(deflectNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
    DeflectNode deflectNode;
};

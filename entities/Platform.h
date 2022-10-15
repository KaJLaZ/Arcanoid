#pragma once

#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/DeflectNode.h"
#include "../nodes/RenderNode.h"

class Platform {
public:
    Platform(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode, DeflectNode deflectNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          constantXMoveNode(std::move(constantXMoveNode)),
          deflectNode(std::move(deflectNode)){}

    std::string getUUID()
    {
        return uuid;
    }
    
    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    ConstantXMoveNode& getConstantXMoveNode()
    {
        return constantXMoveNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
    ConstantXMoveNode constantXMoveNode;
    DeflectNode deflectNode;
};

#pragma once

#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/ReleaseBallNode.h"
#include "../nodes/MouseTrackNode.h"
#include "../nodes/MoveBallNode.h"
#include "../nodes/RenderNode.h"

class Ball
{
public:
    Ball(std::string uuid, ConstantXMoveNode constantXMoveNode, ReleaseBallNode releaseBallNode, MoveBallNode moveBallNode,
        RenderNode renderNode)
        : uuid(std::move(uuid)),
          constantXMoveNode(std::move(constantXMoveNode)),
          releaseBallNode(std::move(releaseBallNode)),
          moveBallNode(std::move(moveBallNode)),
          renderNode(std::move(renderNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    ConstantXMoveNode& getConstantXMoveNode()
    {
        return constantXMoveNode;
    }

    ReleaseBallNode& getReleaseBallNode()
    {
        return releaseBallNode;
    }

    MoveBallNode& getMoveBallNode()
    {
        return moveBallNode;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

private:
    std::string uuid;
    ConstantXMoveNode constantXMoveNode;
    ReleaseBallNode releaseBallNode;
    MoveBallNode moveBallNode;
    RenderNode renderNode;
};

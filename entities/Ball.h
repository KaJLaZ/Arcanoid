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
        RenderNode render_node, MouseTrackNode mouse_track_node)
        : uuid(std::move(uuid)),
          constantXMoveNode(std::move(constantXMoveNode)),
          releaseBallNode(std::move(releaseBallNode)),
          moveBallNode(std::move(moveBallNode)),
          renderNode(std::move(render_node)),
          mouseTrackNode(std::move(mouse_track_node)){}

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

    MouseTrackNode& getMouseTrackNode()
    {
        return mouseTrackNode;
    }

private:
    std::string uuid;
    ConstantXMoveNode constantXMoveNode;
    ReleaseBallNode releaseBallNode;
    MoveBallNode moveBallNode;
    RenderNode renderNode;
    MouseTrackNode mouseTrackNode;
};

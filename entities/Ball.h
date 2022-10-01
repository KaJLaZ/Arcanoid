#pragma once
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/ReleaseBallNode.h"
#include "../nodes/MouseTrackNode.h"
#include "../nodes/MoveBallNode.h"
#include "../nodes/RenderNode.h"

class Ball
{
public:
    Ball(ConstantXMoveNode constant_x_move_node, ReleaseBallNode release_ball_node, MoveBallNode move_ball_node,
        RenderNode render_node, MouseTrackNode mouse_track_node)
        : constantXMoveNode(std::move(constant_x_move_node)),
          releaseBallNode(std::move(release_ball_node)),
          moveBallNode(std::move(move_ball_node)),
          renderNode(std::move(render_node)),
          mouseTrackNode(std::move(mouse_track_node)){}

    ConstantXMoveNode& get_constant_x_move_node()
    {
        return constantXMoveNode;
    }

    ReleaseBallNode& get_release_ball_node()
    {
        return releaseBallNode;
    }

    MoveBallNode& get_move_ball_node()
    {
        return moveBallNode;
    }

    RenderNode& get_render_node()
    {
        return renderNode;
    }

    MouseTrackNode& get_mouse_track_node()
    {
        return mouseTrackNode;
    }

private:
    ConstantXMoveNode constantXMoveNode;
    ReleaseBallNode releaseBallNode;
    MoveBallNode moveBallNode;
    RenderNode renderNode;
    MouseTrackNode mouseTrackNode;
};

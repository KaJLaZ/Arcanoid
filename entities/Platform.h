#pragma once
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/RenderNode.h"

class Platform {
public:
    Platform(RenderNode render_node, ConstantXMoveNode constant_x_move_node)
        : renderNode(std::move(render_node)),
          constantXMoveNode(std::move(constant_x_move_node)){}

    [[nodiscard]] RenderNode& get_render_node()
    {
        return renderNode;
    }

    [[nodiscard]] ConstantXMoveNode& get_constant_x_move_node()
    {
        return constantXMoveNode;
    }

private:
    RenderNode renderNode;
    ConstantXMoveNode constantXMoveNode;
};

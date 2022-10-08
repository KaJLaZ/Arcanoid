#pragma once
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/DeflectNode.h"
#include "../nodes/RenderNode.h"

class Platform {
public:
    Platform(RenderNode renderNode, ConstantXMoveNode constantXMoveNode, DeflectNode deflectNode)
        : renderNode(std::move(renderNode)),
          constantXMoveNode(std::move(constantXMoveNode)),
          deflectNode(std::move(deflectNode)){}

    RenderNode& get_render_node()
    {
        return renderNode;
    }

    ConstantXMoveNode& get_constant_x_move_node()
    {
        return constantXMoveNode;
    }

private:
    RenderNode renderNode;
    ConstantXMoveNode constantXMoveNode;
    DeflectNode deflectNode;
};

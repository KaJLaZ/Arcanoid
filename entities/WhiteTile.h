#pragma once

#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"

class WhiteTile
{
public:
    explicit WhiteTile(RenderNode renderNode, DeflectNode deflectNode)
        : renderNode(std::move(renderNode)),
          deflectNode(deflectNode){}

    RenderNode& get_render_node()
    {
        return renderNode;
    }

private:
    RenderNode renderNode;
    DeflectNode deflectNode;
};

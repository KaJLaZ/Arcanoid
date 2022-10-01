#pragma once

#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"

class WhiteTile
{
public:
    explicit WhiteTile(RenderNode render_node)
        : renderNode(std::move(render_node)){}

    RenderNode& get_render_node()
    {
        return renderNode;
    }

private:
    RenderNode renderNode;
};

#pragma once

#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"

class WhiteTile : public RenderNode
{
public:
    WhiteTile(Sprite* sprite, Coord* coord, Size size, int* healthPoints)
        : RenderNode(sprite, coord, std::move(size)){}
};

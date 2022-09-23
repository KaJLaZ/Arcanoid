#pragma once
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"

class RenderNode
{
public:
    RenderNode(Sprite* sprite, Coord* coord, Size size)
        : sprite(sprite),
          coord(coord),
          size(size){}

    Sprite* getSprite() const
    {
        return sprite;
    }

    //todo fix ambiqous it can be fixed inheritance from components
    Coord* getRenderNodeCoord()
    {
        return coord;
    }

    Size getSize() const
    {
        return size;
    }

    friend bool operator==(const RenderNode& lhs, const RenderNode& rhs)
    {
        return std::tie(lhs.sprite, lhs.coord, lhs.size) == std::tie(rhs.sprite, rhs.coord, rhs.size);
    }

private:
    Sprite* sprite;
    Coord* coord;
    Size size;
};

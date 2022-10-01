#pragma once
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"

class RenderNode
{
public:
    RenderNode(std::shared_ptr<Sprite> sprite, std::shared_ptr<Coord> coord, Size size)
        : sprite(std::move(sprite)),
          coord(std::move(coord)),
          size(size){}

    std::shared_ptr<Sprite> getSprite() const
    {
        return sprite;
    }
    
    std::shared_ptr<Coord> getCoord()
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
    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<Coord> coord;
    Size size;
};

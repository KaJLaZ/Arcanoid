#pragma once

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
    
    Coord getCoord()
    {
        return *coord;
    }

    Size getSize() const
    {
        return size;
    }

private:
    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<Coord> coord;
    Size size;
};

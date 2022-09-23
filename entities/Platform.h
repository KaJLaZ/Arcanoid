#pragma once
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/RenderNode.h"

class Platform : public RenderNode, public ConstantXMoveNode {
public:
    Platform(Sprite* sprite, Coord* coord, Size&& size, int moveDistance)
        : RenderNode(sprite, coord, size),
          ConstantXMoveNode(coord, moveDistance){}
};

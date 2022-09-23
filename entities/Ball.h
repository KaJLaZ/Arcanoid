#pragma once

#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../nodes/ReleaseBallNode.h"
#include "../nodes/MouseTrackNode.h"
#include "../nodes/MoveBallNode.h"
#include "../nodes/RenderNode.h"

class Ball : public ConstantXMoveNode, public ReleaseBallNode,  public MoveBallNode,
public RenderNode, public MouseTrackNode
{
public:
    Ball(Sprite* sprite, Coord* ballCoord, Coord* mouseCoord,
        Size size, Speed* releasedSpeed, int unreleasedSpeed, double baseSpeed):
        
          ConstantXMoveNode(ballCoord, unreleasedSpeed),
          ReleaseBallNode(ballCoord, mouseCoord, releasedSpeed, baseSpeed),
          MoveBallNode(ballCoord, releasedSpeed),
          RenderNode(sprite, ballCoord, size),
          MouseTrackNode(mouseCoord){}
};

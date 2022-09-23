#pragma once

#include "../systems/ConstantXMoveSystem.h"
#include "../systems/MouseTrackSystem.h"
#include "../systems/MoveBallSystem.h"
#include "../systems/ReleaseBallSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/DeflectSystem.h"
#include "../systems/TileHealthSystem.h"

class SystemManager
{
public:
    RenderSystem& getRenderSystem()
    {
        return renderSystem;
    }

    ConstantXMoveSystem& getConstantXMoveSystem()
    {
        return constantXMoveSystem;
    }

    ReleaseBallSystem& getreleaseBallSystem()
    {
        return releaseBallSystem;
    }

    MoveBallSystem& getMoveBallSystem()
    {
        return moveBallSystem;
    }

    MouseTrackSystem& getMouseTrackSystem()
    {
        return mouseTrackSystem;
    }

    DeflectSystem& getDeflectSystem()
    {
        return tileDeflectSystem;
    }

    TileHealthSystem& getTileHealthSystem()
    {
        return tileHealthSystem;
    }

private:
    RenderSystem renderSystem;
    ConstantXMoveSystem constantXMoveSystem;
    ReleaseBallSystem releaseBallSystem;
    MoveBallSystem moveBallSystem;
    MouseTrackSystem mouseTrackSystem;
    DeflectSystem tileDeflectSystem;
    TileHealthSystem tileHealthSystem;
};

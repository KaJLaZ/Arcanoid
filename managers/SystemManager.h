#pragma once

#include "../systems/ConstantXMoveSystem.h"
#include "../systems/MouseTrackSystem.h"
#include "../systems/MoveBallSystem.h"
#include "../systems/ReleaseBallSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/DeflectSystem.h"
#include "../systems/PressedKeyTrackSystem.h"

class SystemManager
{
public:
    SystemManager(std::shared_ptr<RenderSystem> render_system, std::shared_ptr<ConstantXMoveSystem> constant_x_move_system,
        std::shared_ptr<ReleaseBallSystem> release_ball_system, std::shared_ptr<MoveBallSystem> move_ball_system,
        std::shared_ptr<MouseTrackSystem> mouse_track_system, std::shared_ptr<DeflectSystem> tile_deflect_system,
        std::shared_ptr<PressedKeyTrackSystem> pressedKeyTrackSystem)
        : renderSystem(std::move(render_system)),
          constantXMoveSystem(std::move(constant_x_move_system)),
          releaseBallSystem(std::move(release_ball_system)),
          moveBallSystem(std::move(move_ball_system)),
          mouseTrackSystem(std::move(mouse_track_system)),
          tileDeflectSystem(std::move(tile_deflect_system)),
          pressedKeyTrackSystem(std::move(pressedKeyTrackSystem)){}

    std::shared_ptr<RenderSystem> getRenderSystem()
    {
        return renderSystem;
    }

    std::shared_ptr<ConstantXMoveSystem> getConstantXMoveSystem()
    {
        return constantXMoveSystem;
    }

    std::shared_ptr<ReleaseBallSystem> getreleaseBallSystem()
    {
        return releaseBallSystem;
    }

    std::shared_ptr<MoveBallSystem> getMoveBallSystem()
    {
        return moveBallSystem;
    }

    std::shared_ptr<MouseTrackSystem> getMouseTrackSystem()
    {
        return mouseTrackSystem;
    }

    std::shared_ptr<DeflectSystem> getDeflectSystem()
    {
        return tileDeflectSystem;
    }

    std::shared_ptr<PressedKeyTrackSystem> getPressedKeyTrackSystem()
    {
        return pressedKeyTrackSystem;
    }

private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<ConstantXMoveSystem> constantXMoveSystem;
    std::shared_ptr<ReleaseBallSystem> releaseBallSystem;
    std::shared_ptr<MoveBallSystem> moveBallSystem;
    std::shared_ptr<MouseTrackSystem> mouseTrackSystem;
    std::shared_ptr<DeflectSystem> tileDeflectSystem;
    std::shared_ptr<PressedKeyTrackSystem> pressedKeyTrackSystem;
};

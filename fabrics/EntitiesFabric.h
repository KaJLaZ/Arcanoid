#pragma once

#include "../entities/Platform.h"
#include "../entities/WhiteTile.h"
#include "../entities/Ball.h"
#include "../managers/EntityManager.h"
#include "../managers/SystemManager.h"
#include "../systems/ConstantXMoveSystem.h"
#include "../systems/MoveBallSystem.h"
#include "../systems/ReleaseBallSystem.h"
#include "../systems/RenderSystem.h"

class EntitiesFabric
{
public:
    static Platform* makePlatformEntity(config::PlatformStartConfig& config)
    {
        return new Platform(
            createSprite(config.spriteFilePath.c_str()),
            new Coord(config.posX, config.posY),
            Size(config.width, config.height),
            config.moveDistance);
    }

    static Ball* makeBallEntity(config::BallStartConfig& config)
    {
        return new Ball(
            createSprite(config.spriteFilePath.c_str()),
            new Coord(config.posX, config.posY),
            new Coord(config.posX, config.posY),
             Size(config.width, config.height),
             new Speed(config.speedX, config.speedY),
            config.unreleasedMoveDistance, config.baseSpeed);
    }

    static WhiteTile* makeWhiteTitleEntity(config::WhiteTileStartConfig& config)
    {
        return new WhiteTile(
            createSprite(config.spriteFilePath.c_str()),
            new Coord(config.posX, config.posY),
            Size(config.width, config.height),
            new int(config.healthPoints));
    }

    static EntityManager* makeEntityManager(SystemManager* systemManager)
    {
        config::ConfigsHolder configsHolder;

        auto platformConfig = configsHolder.getPlatformStartConfig();
        auto adjPlatformConfig = config::ConfigResolutionAdjuster::adjustPlatformConfig(platformConfig);
        auto platform = makePlatformEntity(adjPlatformConfig);

        auto ballConfig = configsHolder.getBallStartConfig();
        auto adjustedBallConfig = config::ConfigResolutionAdjuster::adjustBallConfig(ballConfig);
        auto ball = makeBallEntity(adjustedBallConfig);

        auto tileConfig = configsHolder.getWhiteTileStartConfig();
        auto adjustedTileConfig = config::ConfigResolutionAdjuster::adjustWhiteTileConfig(tileConfig);
        auto whiteTile = makeWhiteTitleEntity(adjustedTileConfig);
        
        auto entityManager = new EntityManager(configsHolder, platform, ball, whiteTile);

        initPlatformEntity(systemManager->getRenderSystem(), systemManager->getConstantXMoveSystem(), platform);
        initWhiteTileEntity(systemManager->getRenderSystem(), whiteTile);
        initBallEntity(systemManager->getRenderSystem(), systemManager->getConstantXMoveSystem(),
            systemManager->getreleaseBallSystem(), ball);

        return entityManager;
    }
    
private:
    static void initPlatformEntity(RenderSystem& renderSystem, ConstantXMoveSystem& constantXMoveSystem, Platform* platform)
    {
        renderSystem.addNode(*platform);
        constantXMoveSystem.addNode(*platform);
    }

    static void initWhiteTileEntity(RenderSystem& renderSystem, WhiteTile* tile)
    {
        renderSystem.addNode(*tile);
    }

    static void initBallEntity(RenderSystem& renderSystem, ConstantXMoveSystem& constantXMoveSystem,
        ReleaseBallSystem& releaseBallSystem, Ball* ball)
    {
        renderSystem.addNode(*ball);
        constantXMoveSystem.addNode(*ball);
        releaseBallSystem.addNode(*ball);
    }
};

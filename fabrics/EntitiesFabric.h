#pragma once

#include <memory>
#include "../configs/ConfigResolutionAdjuster.h"
#include "../entities/Ball.h"
#include "../entities/Platform.h"
#include "../entities/WhiteTile.h"
#include "../managers/EntityManager.h"
#include "../managers/SystemManager.h"
#include "../systems/ConstantXMoveSystem.h"
#include "../systems/MoveBallSystem.h"
#include "../systems/ReleaseBallSystem.h"
#include "../systems/RenderSystem.h"
#include "../utilities/UUID.h"

class EntitiesFabric
{
public:
    static ConstantXMoveNode makeConstantXMoveNode(std::shared_ptr<Coord> coord, std::shared_ptr<int> moveDistance,
        std::shared_ptr<FRKey> pressedKey)
    {
        return {std::move(coord), std::move(moveDistance), std::move(pressedKey)};
    }

    static DeflectNode makeDeflectNode(std::shared_ptr<Coord> ballCord, std::shared_ptr<Coord> targetCord,
        std::shared_ptr<Speed> ballSpeed, Size ballSize, Size targetSize)
    {
        return {std::move(ballCord), std::move(targetCord), std::move(ballSpeed), ballSize, targetSize};
    }

    static MouseTrackNode makeMouseTrackNode(std::shared_ptr<Coord> mouseCoord)
    {
        return {std::move(mouseCoord)};
    }

    static PressedKeyTrackNode makePressedKeyTrackNode(std::shared_ptr<FRKey> key)
    {
        return {std::move(key)};
    }

    static MoveBallNode makeMoveBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Speed> speed)
    {
        return {std::move(ballCoord), std::move(speed)};
    }

    static ReleaseBallNode makeReleaseBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<Speed> ballSpeed, std::shared_ptr<double> baseSpeed)
    {
        return {std::move(ballCoord), std::move(mouseCoord), std::move(ballSpeed), std::move(baseSpeed)};
    }

    static RenderNode makeRenderNode(std::shared_ptr<Sprite> sprite, std::shared_ptr<Coord> coord, Size size)
    {
        return {std::move(sprite), std::move(coord), size};
    }
    
    static Platform makePlatformEntity(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode, DeflectNode deflectNode)
    {
        return {std::move(uuid), std::move(renderNode), std::move(constantXMoveNode), std::move(deflectNode)};
    }

    static Ball makeBallEntity(std::string uuid, ConstantXMoveNode constantXMoveNode, ReleaseBallNode releaseBallNode,
        MoveBallNode moveBallNode, RenderNode renderNode)
    {
        return {std::move(uuid), std::move(constantXMoveNode), std::move(releaseBallNode),
            std::move(moveBallNode), std::move(renderNode)};
    }

    static WhiteTile makeTitleEntity(std::string uuid, RenderNode renderNode, DeflectNode deflectNode)
    {
        return {std::move(uuid), std::move(renderNode), std::move(deflectNode)};
    }

    static UserInputTracker makeUserInputTrackerEntity(std::string uuid, MouseTrackNode mouseTrackNode,
        PressedKeyTrackNode pressedKeyTrackNode)
    {
        return {std::move(uuid), std::move(mouseTrackNode), std::move(pressedKeyTrackNode)};
    }

    static EntityManager makeEntityManager(std::shared_ptr<ConfigsHolder> configsHolder,
        std::shared_ptr<SharedComponentHolder> componentHolder,
        std::shared_ptr<SystemManager> systemManager, ScreenResolution screenResolution)
    {
        auto platformConfig = configsHolder->getPlatformConfig();
        auto ballConfig = configsHolder->getBallConfig();
        auto tileConfig = configsHolder->getWhiteTileConfig();
        
        auto platformSize = Size(platformConfig.width, platformConfig.height);
        auto ballSize = Size(ballConfig.width, ballConfig.height);
        auto tileSize = Size(tileConfig.width, tileConfig.height);
        auto leftBorderTileSize = Size(10, screenResolution.height);
        auto topBorderTileSize = Size(screenResolution.width,10);
        auto rightBorderTileSize = Size(10, screenResolution.height);
        
        std::shared_ptr<Sprite> platformSprite(createSprite(platformConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> ballSprite(createSprite(ballConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> tileSprite(createSprite(tileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> leftBorderTileSprite(createSprite(tileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> topBorderTileSprite(createSprite(tileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> rightBorderTileSprite(createSprite(tileConfig.spriteFilePath.c_str()));


        auto platformRenderNode = makeRenderNode(platformSprite, componentHolder->getPlatformCoord(), platformSize);
        auto ballRenderNode = makeRenderNode(ballSprite, componentHolder->getBallCoord(), ballSize);
        auto tileRenderNode = makeRenderNode(tileSprite, componentHolder->getTileCoord(), tileSize);
        auto leftBorderTileRenderNode = makeRenderNode(leftBorderTileSprite, componentHolder->getLeftBorderTileCoord(), leftBorderTileSize);
        auto topBorderTileRenderNode = makeRenderNode(topBorderTileSprite, componentHolder->getTopBorderTileCoord(), topBorderTileSize);
        auto rightBorderTileRenderNode = makeRenderNode(rightBorderTileSprite, componentHolder->getRightBorderTileCoord(), rightBorderTileSize);

        auto constantBallMoveNode = makeConstantXMoveNode(componentHolder->getBallCoord(),
            std::make_shared<int>(ballConfig.unreleasedMoveDistance), componentHolder->getPressedKey());
        auto platformConstantXMoveNode = makeConstantXMoveNode(componentHolder->getPlatformCoord(),
            std::make_shared<int>(platformConfig.moveDistance), componentHolder->getPressedKey());
        
        auto moveBallNode = makeMoveBallNode(componentHolder->getBallCoord(), componentHolder->getBallSpeed());
        auto mouseTrackNode = makeMouseTrackNode(componentHolder->getMouseCoord());
        auto pressedKeyTrackNode = makePressedKeyTrackNode(componentHolder->getPressedKey());
        auto releasedBallNode = makeReleaseBallNode(componentHolder->getBallCoord(), componentHolder->getMouseCoord(),
            componentHolder->getBallSpeed(),
            std::make_shared<double>(ballConfig.baseSpeed));
        
        
        auto platformDeflectNode = makeDeflectNode(componentHolder->getBallCoord(), componentHolder->getPlatformCoord(), componentHolder->getBallSpeed(), ballSize,platformSize);
        auto whiteTileDeflectNode = makeDeflectNode(componentHolder->getBallCoord(), componentHolder->getTileCoord(), componentHolder->getBallSpeed(), ballSize, tileSize);
        auto leftBorderTileDeflectNode = makeDeflectNode(componentHolder->getBallCoord(),
            componentHolder->getLeftBorderTileCoord(), componentHolder->getBallSpeed(), ballSize, leftBorderTileSize);
        auto topBorderTileDeflectNode = makeDeflectNode(componentHolder->getBallCoord(),
            componentHolder->getTopBorderTileCoord(), componentHolder->getBallSpeed(), ballSize, topBorderTileSize);
        auto rightBorderTileDeflectNode = makeDeflectNode(componentHolder->getBallCoord(),componentHolder->getRightBorderTileCoord(),
            componentHolder->getBallSpeed(), ballSize, rightBorderTileSize);


        auto ball = makeBallEntity(UUID::generate(), constantBallMoveNode, releasedBallNode,
            moveBallNode, ballRenderNode);
        auto platform = makePlatformEntity(UUID::generate(), platformRenderNode, platformConstantXMoveNode, platformDeflectNode);
        auto whiteTile = makeTitleEntity(UUID::generate(), tileRenderNode, whiteTileDeflectNode);
        auto userInputTracker = makeUserInputTrackerEntity(UUID::generate(), mouseTrackNode, pressedKeyTrackNode);
        auto leftBorderTile = makeTitleEntity(UUID::generate(), leftBorderTileRenderNode, leftBorderTileDeflectNode);
        auto topBorderTile = makeTitleEntity(UUID::generate(), topBorderTileRenderNode, topBorderTileDeflectNode);
        auto rightBorderTile = makeTitleEntity(UUID::generate(), rightBorderTileRenderNode, rightBorderTileDeflectNode);

        
        EntityManager entityManager(platform, ball, whiteTile, userInputTracker, leftBorderTile, topBorderTile, rightBorderTile);

        systemManager->getreleaseBallSystem()->addNode(ball.getUUID(), releasedBallNode);
        systemManager->getMouseTrackSystem()->addNode(userInputTracker.getUUID(), mouseTrackNode);
        systemManager->getPressedKeyTrackSystem()->addNode(userInputTracker.getUUID(), pressedKeyTrackNode);
        
        systemManager->getRenderSystem()->addNode(platform.getUUID(), platformRenderNode);
        systemManager->getRenderSystem()->addNode(ball.getUUID(), ballRenderNode);
        systemManager->getRenderSystem()->addNode(whiteTile.getUUID(), tileRenderNode);
        systemManager->getRenderSystem()->addNode(leftBorderTile.getUUID(), leftBorderTileRenderNode);
        systemManager->getRenderSystem()->addNode(topBorderTile.getUUID(), topBorderTileRenderNode);
        systemManager->getRenderSystem()->addNode(rightBorderTile.getUUID(), rightBorderTileRenderNode);
        
        systemManager->getConstantXMoveSystem()->addNode(platform.getUUID(), platformConstantXMoveNode);
        systemManager->getConstantXMoveSystem()->addNode(ball.getUUID(), constantBallMoveNode);

        systemManager->getDeflectSystem()->addNode(platform.getUUID(), platformDeflectNode);
        systemManager->getDeflectSystem()->addNode(whiteTile.getUUID(), whiteTileDeflectNode);
        systemManager->getDeflectSystem()->addNode(leftBorderTile.getUUID(), leftBorderTileDeflectNode);
        systemManager->getDeflectSystem()->addNode(topBorderTile.getUUID(), topBorderTileDeflectNode);
        systemManager->getDeflectSystem()->addNode(rightBorderTile.getUUID(), rightBorderTileDeflectNode);

        return entityManager;
    }

    static std::shared_ptr<SystemManager> systemManager()
    {
        return std::make_shared<SystemManager>(SystemManager(std::make_shared<RenderSystem>(RenderSystem(std::unordered_map<std::string, RenderNode>())),
            std::make_shared<ConstantXMoveSystem>(ConstantXMoveSystem(std::unordered_map<std::string, ConstantXMoveNode>())),
            std::make_shared<ReleaseBallSystem>(ReleaseBallSystem(std::unordered_map<std::string, ReleaseBallNode>())),
            std::make_shared<MoveBallSystem>(MoveBallSystem(std::unordered_map<std::string, MoveBallNode>())),
            std::make_shared<MouseTrackSystem>(MouseTrackSystem(std::unordered_map<std::string, MouseTrackNode>())),
            std::make_shared<DeflectSystem>(DeflectSystem(std::unordered_map<std::string, DeflectNode>())),
            std::make_shared<PressedKeyTrackSystem>(PressedKeyTrackSystem(std::unordered_map<std::string, PressedKeyTrackNode>()))));
    }
};

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

    static EntityManager makeEntityManager(config::ConfigsHolder* configsHolder, std::shared_ptr<SystemManager> systemManager)
    {
        auto platformConfig = configsHolder->getPlatformConfig();
        auto adjPlatformConfig = config::ConfigResolutionAdjuster::adjustPlatformConfig(platformConfig);

        auto ballConfig = configsHolder->getBallConfig();
        auto adjBallConfig = config::ConfigResolutionAdjuster::adjustBallConfig(ballConfig);

        auto tileConfig = configsHolder->getWhiteTileConfig();
        auto adjTileConfig = config::ConfigResolutionAdjuster::adjustWhiteTileConfig(tileConfig);

        
        auto platformCoord = std::make_shared<Coord>(Coord(adjPlatformConfig.posX, adjPlatformConfig.posY));
        auto ballCoord = std::make_shared<Coord>(Coord(adjBallConfig.posX, adjBallConfig.posY));
        auto mouseCoord = std::make_shared<Coord>(Coord(0, 0));
        auto tileCoord = std::make_shared<Coord>(Coord(adjTileConfig.posX, adjTileConfig.posY));
        auto leftBorderTileCoord = std::make_shared<Coord>(Coord(0,0));
        auto topBorderTileCoord = std::make_shared<Coord>(Coord(11,0));
        auto rightBorderTileCoord = std::make_shared<Coord>(Coord(ScreenResolution::WIDTH - 11, 11));
        
        auto platformSize = Size(adjPlatformConfig.width, adjPlatformConfig.height);
        auto ballSize = Size(adjBallConfig.width, adjBallConfig.height);
        auto tileSize = Size(adjTileConfig.width, adjTileConfig.height);
        auto leftBorderTileSize = Size(10,ScreenResolution::HEIGHT);
        auto topBorderTileSize = Size(ScreenResolution::WIDTH,10);
        auto rightBorderTileSize = Size(10, ScreenResolution::HEIGHT);

        auto ballSpeed = std::make_shared<Speed>(Speed(adjBallConfig.speedX, adjBallConfig.speedY));
        auto pressedKey = std::make_shared<FRKey>(FRKey::UP);
        
        std::shared_ptr<Sprite> platformSprite(createSprite(adjPlatformConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> ballSprite(createSprite(adjBallConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> tileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> leftBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> topBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> rightBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));


        auto platformRenderNode = makeRenderNode(platformSprite,platformCoord, platformSize);
        auto ballRenderNode = makeRenderNode(ballSprite, ballCoord, ballSize);
        auto tileRenderNode = makeRenderNode(tileSprite, tileCoord, tileSize);
        auto leftBorderTileRenderNode = makeRenderNode(leftBorderTileSprite, leftBorderTileCoord, leftBorderTileSize);
        auto topBorderTileRenderNode = makeRenderNode(topBorderTileSprite, topBorderTileCoord, topBorderTileSize);
        auto rightBorderTileRenderNode = makeRenderNode(rightBorderTileSprite, rightBorderTileCoord, rightBorderTileSize);

        auto constantBallMoveNode = makeConstantXMoveNode(ballCoord,
            std::make_shared<int>(adjBallConfig.unreleasedMoveDistance), pressedKey);
        auto platformConstantXMoveNode = makeConstantXMoveNode(platformCoord,
            std::make_shared<int>(adjPlatformConfig.moveDistance), pressedKey);
        
        auto moveBallNode = makeMoveBallNode(ballCoord, ballSpeed);
        auto mouseTrackNode = makeMouseTrackNode(mouseCoord);
        auto pressedKeyTrackNode = makePressedKeyTrackNode(pressedKey);
        auto releasedBallNode = makeReleaseBallNode(ballCoord, mouseCoord, ballSpeed,
            std::make_shared<double>(adjBallConfig.baseSpeed));
        
        
        auto platformDeflectNode = makeDeflectNode(ballCoord, platformCoord, ballSpeed, ballSize,platformSize);
        auto whiteTileDeflectNode = makeDeflectNode(ballCoord, tileCoord, ballSpeed, ballSize, tileSize);
        auto leftBorderTileDeflectNode = makeDeflectNode(ballCoord, leftBorderTileCoord,
            ballSpeed, ballSize, leftBorderTileSize);
        auto topBorderTileDeflectNode = makeDeflectNode(ballCoord, topBorderTileCoord,
            ballSpeed, ballSize, topBorderTileSize);
        auto rightBorderTileDeflectNode = makeDeflectNode(ballCoord,rightBorderTileCoord,
            ballSpeed, ballSize, rightBorderTileSize);


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

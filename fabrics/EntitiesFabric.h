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
    static ConstantXMoveNode* makeConstanXMoveNode(std::shared_ptr<Coord> coord, std::shared_ptr<int> moveDistance)
    {
        return new ConstantXMoveNode(std::move(coord), std::move(moveDistance));
    }

    static DeflectNode* makeDeflectNode(std::shared_ptr<Coord> ballCord, std::shared_ptr<Coord> targetCord,
        std::shared_ptr<Speed> ballSpeed, Size ballSize, Size targetSize)
    {
        return new DeflectNode(std::move(ballCord), std::move(targetCord), std::move(ballSpeed), ballSize, targetSize);
    }

    static MouseTrackNode* makeMouseTrackNode(std::shared_ptr<Coord> mouseCoord)
    {
        return new MouseTrackNode(std::move(mouseCoord));
    }

    static MoveBallNode* makeMoveBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Speed> speed)
    {
        return new MoveBallNode(std::move(ballCoord), std::move(speed));
    }

    static ReleaseBallNode* makeReleaseBallNode(std::shared_ptr<Coord> ballCoord, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<Speed> ballSpeed, std::shared_ptr<double> baseSpeed)
    {
        return new ReleaseBallNode(std::move(ballCoord), std::move(mouseCoord), std::move(ballSpeed), std::move(baseSpeed));
    }

    static RenderNode* makeRenderNode(std::shared_ptr<Sprite> sprite, std::shared_ptr<Coord> coord, Size size)
    {
        return new RenderNode(std::move(sprite), std::move(coord), size);
    }
    
    static Platform* makePlatformEntity(std::string uuid, RenderNode& renderNode, ConstantXMoveNode& constantXMoveNode, DeflectNode deflectNode)
    {
        return new Platform(uuid, renderNode, constantXMoveNode, deflectNode);
    }

    static Ball* makeBallEntity(std::string uuid, ConstantXMoveNode& constantXMoveNode, ReleaseBallNode& releaseBallNode,
        MoveBallNode& moveBallNode, RenderNode& renderNode, MouseTrackNode& mouseTrackNode)
    {
        return new Ball(uuid, constantXMoveNode, releaseBallNode, moveBallNode, renderNode, mouseTrackNode);
    }

    static WhiteTile* makeWhiteTitleEntity(std::string uuid, RenderNode& renderNode, DeflectNode& deflectNode)
    {
        return new WhiteTile(uuid, renderNode, deflectNode);
    }

    static EntityManager* makeEntityManager(config::ConfigsHolder* configsHolder, SystemManager* systemManager)
    {
        auto platformConfig = configsHolder->getPlatformStartConfig();
        auto adjPlatformConfig = config::ConfigResolutionAdjuster::adjustPlatformConfig(platformConfig);

        auto ballConfig = configsHolder->getBallStartConfig();
        auto adjBallConfig = config::ConfigResolutionAdjuster::adjustBallConfig(ballConfig);

        auto tileConfig = configsHolder->getWhiteTileStartConfig();
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
        
        std::shared_ptr<Sprite> platformSprite(createSprite(adjPlatformConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> ballSprite(createSprite(adjBallConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> tileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> leftBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> topBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        std::shared_ptr<Sprite> rightBorderTileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));


        auto platformRenderNode = makeRenderNode(std::move(platformSprite),platformCoord, platformSize);
        auto ballRenderNode = makeRenderNode(ballSprite, ballCoord, ballSize);
        auto tileRenderNode = makeRenderNode(tileSprite, tileCoord, tileSize);
        auto leftBorderTileRenderNode = makeRenderNode(leftBorderTileSprite, leftBorderTileCoord, leftBorderTileSize);
        auto topBorderTileRenderNode = makeRenderNode(topBorderTileSprite, topBorderTileCoord, topBorderTileSize);
        auto rightBorderTileRenderNode = makeRenderNode(rightBorderTileSprite, rightBorderTileCoord, rightBorderTileSize);

        auto constantBallMoveNode = makeConstanXMoveNode(ballCoord,
            std::make_shared<int>(adjBallConfig.unreleasedMoveDistance));
        auto platformConstantXMoveNode = makeConstanXMoveNode(platformCoord,
            std::make_shared<int>(adjPlatformConfig.moveDistance));
        
        auto moveBallNode = makeMoveBallNode(ballCoord, ballSpeed);
        auto mouseTrackNode = makeMouseTrackNode(mouseCoord);
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


        auto ball = makeBallEntity(UUID::generate(), *constantBallMoveNode, *releasedBallNode,
            *moveBallNode, *ballRenderNode, *mouseTrackNode);
        auto platform = makePlatformEntity(UUID::generate(), *platformRenderNode, *platformConstantXMoveNode, *platformDeflectNode);
        auto whiteTile = makeWhiteTitleEntity(UUID::generate(), *tileRenderNode, *whiteTileDeflectNode);
        auto leftBorderTile = makeWhiteTitleEntity(UUID::generate(), *leftBorderTileRenderNode, *leftBorderTileDeflectNode);
        auto topBorderTile = makeWhiteTitleEntity(UUID::generate(), *topBorderTileRenderNode, *topBorderTileDeflectNode);
        auto rightBorderTile = makeWhiteTitleEntity(UUID::generate(), *rightBorderTileRenderNode, *rightBorderTileDeflectNode);

        
        auto entityManager = new EntityManager(*platform, *ball, *whiteTile, *leftBorderTile, *topBorderTile, *rightBorderTile);

        systemManager->getRenderSystem().addNode(*platformRenderNode);
        systemManager->getRenderSystem().addNode(*ballRenderNode);
        systemManager->getRenderSystem().addNode(*tileRenderNode);
        systemManager->getRenderSystem().addNode(*leftBorderTileRenderNode);
        systemManager->getRenderSystem().addNode(*topBorderTileRenderNode);
        systemManager->getRenderSystem().addNode(*rightBorderTileRenderNode);
        
        systemManager->getConstantXMoveSystem().addNode(*platformConstantXMoveNode);
        systemManager->getConstantXMoveSystem().addNode(*constantBallMoveNode);
        
        systemManager->getreleaseBallSystem().addNode(*releasedBallNode);

        systemManager->getDeflectSystem().addNode(platformDeflectNode);
        systemManager->getDeflectSystem().addNode(whiteTileDeflectNode);
        systemManager->getDeflectSystem().addNode(leftBorderTileDeflectNode);
        systemManager->getDeflectSystem().addNode(topBorderTileDeflectNode);
        systemManager->getDeflectSystem().addNode(rightBorderTileDeflectNode);

        return entityManager;
    }
};

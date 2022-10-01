#pragma once

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

class EntitiesFabric
{
public:
    static ConstantXMoveNode* makeConstanXMoveNode(std::shared_ptr<Coord> coord, std::shared_ptr<int> moveDistance)
    {
        return new ConstantXMoveNode(std::move(coord), std::move(moveDistance));
    }

    static DeflectNode* makeDeflectNode(std::shared_ptr<Coord> ballCord, std::shared_ptr<Coord> targetCord,
        std::shared_ptr<Speed> ballSpeed, Size ballSize, Size targetSize, DeflectNode::Target target,
        std::shared_ptr<double> baseSpeed)
    {
        return new DeflectNode(std::move(ballCord), std::move(targetCord), std::move(ballSpeed), ballSize, targetSize, target, std::move(baseSpeed));
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
    
    static Platform* makePlatformEntity(RenderNode& renderNode, ConstantXMoveNode& constantXMoveNode)
    {
        return new Platform(renderNode, constantXMoveNode);
    }

    static Ball* makeBallEntity(ConstantXMoveNode& constantXMoveNode, ReleaseBallNode& releaseBallNode,
        MoveBallNode& moveBallNode, RenderNode& renderNode, MouseTrackNode& mouseTrackNode)
    {
        return new Ball(constantXMoveNode, releaseBallNode, moveBallNode, renderNode, mouseTrackNode);
    }

    static WhiteTile* makeWhiteTitleEntity(RenderNode& renderNode)
    {
        return new WhiteTile(renderNode);
    }

    static EntityManager* makeEntityManager(config::ConfigsHolder* configsHolder, SystemManager* systemManager)
    {
        auto platformConfig = configsHolder->getPlatformStartConfig();
        auto adjPlatformConfig = config::ConfigResolutionAdjuster::adjustPlatformConfig(platformConfig);

        auto platformCoord = std::make_shared<Coord>(Coord(adjPlatformConfig.posX, adjPlatformConfig.posY));
        std::shared_ptr<Sprite> platformSprite(createSprite(adjPlatformConfig.spriteFilePath.c_str()));
        
        auto platformRenderNode = makeRenderNode(std::move(platformSprite),platformCoord,
                Size(adjPlatformConfig.width, adjPlatformConfig.height));
        
        auto platformConstantXMoveNode = makeConstanXMoveNode(platformCoord,
            std::make_shared<int>(adjPlatformConfig.moveDistance));
        auto platform = makePlatformEntity(*platformRenderNode, *platformConstantXMoveNode);

        
        auto ballConfig = configsHolder->getBallStartConfig();
        auto adjBallConfig = config::ConfigResolutionAdjuster::adjustBallConfig(ballConfig);
        
        auto ballCoord = std::make_shared<Coord>(Coord(adjBallConfig.posX, adjBallConfig.posY));
        auto mouseCoord = std::make_shared<Coord>(Coord(0, 0));
        auto ballSpeed = std::make_shared<Speed>(Speed(adjBallConfig.speedX, adjBallConfig.speedY));
        std::shared_ptr<Sprite> ballSprite(createSprite(adjBallConfig.spriteFilePath.c_str()));
        
        auto constantBallMoveNode = makeConstanXMoveNode(ballCoord,
            std::make_shared<int>(adjBallConfig.unreleasedMoveDistance));
        auto releasedBallNode = makeReleaseBallNode(ballCoord, mouseCoord, ballSpeed,
            std::make_shared<double>(adjBallConfig.baseSpeed));
        auto moveBallNode = makeMoveBallNode(ballCoord, ballSpeed);
        auto ballRenderNode = makeRenderNode(ballSprite,
        ballCoord,
        Size(adjBallConfig.width, adjBallConfig.height));
        auto mouseTrackNode = makeMouseTrackNode(mouseCoord);
        
        auto ball = makeBallEntity(*constantBallMoveNode, *releasedBallNode,
            *moveBallNode, *ballRenderNode, *mouseTrackNode);

        
        auto tileConfig = configsHolder->getWhiteTileStartConfig();
        auto adjTileConfig = config::ConfigResolutionAdjuster::adjustWhiteTileConfig(tileConfig);

        auto tileCoord = std::make_shared<Coord>(Coord(adjTileConfig.posX, adjTileConfig.posY));
        std::shared_ptr<Sprite> tileSprite(createSprite(adjTileConfig.spriteFilePath.c_str()));
        
        auto tileRenderNode = makeRenderNode(tileSprite,
            tileCoord, Size(adjTileConfig.width, adjTileConfig.height));
        
        auto whiteTile = makeWhiteTitleEntity(*tileRenderNode);

        
        auto entityManager = new EntityManager(platform, ball, whiteTile);

        systemManager->getRenderSystem().addNode(*platformRenderNode);
        systemManager->getConstantXMoveSystem().addNode(*platformConstantXMoveNode);

        systemManager->getRenderSystem().addNode(*ballRenderNode);
        systemManager->getConstantXMoveSystem().addNode(*constantBallMoveNode);
        systemManager->getreleaseBallSystem().addNode(*releasedBallNode);

        systemManager->getRenderSystem().addNode(*tileRenderNode);

        return entityManager;
    }
};

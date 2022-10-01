#pragma once

#include "../managers/EntityManager.h"

class Crutch
{
public:
    static void afterBallRelleaseInitialization(SystemManager* systemManager, EntityManager* entityManager)
    {
        Ball& ball = entityManager->getBall();
        systemManager->getConstantXMoveSystem().removeNode(ball.get_constant_x_move_node());
        systemManager->getreleaseBallSystem().process();
        systemManager->getreleaseBallSystem().removeNodes();
        systemManager->getMoveBallSystem().addNode(ball.get_move_ball_node());

        WhiteTile& tile = entityManager->getWhiteTile();
        auto whiteTileDeflectNode = new DeflectNode(ball.get_release_ball_node().getReleaseBallCoord(),
            tile.get_render_node().getCoord(),
            ball.get_move_ball_node().getSpeed(),
            ball.get_render_node().getSize(),
            tile.get_render_node().getSize(),
            DeflectNode::Target::Tile,
            ball.get_release_ball_node().getBaseSpeed());

        Platform& platform = entityManager->getPlatform();
            
        auto platformDeflectNode = new DeflectNode(ball.get_release_ball_node().getReleaseBallCoord(),
        platform.get_render_node().getCoord(),
        ball.get_move_ball_node().getSpeed(),
        ball.get_render_node().getSize(),
        platform.get_render_node().getSize(),
        DeflectNode::Target::Platform,
        ball.get_release_ball_node().getBaseSpeed());
			
        auto leftBorder = new DeflectNode(ball.get_release_ball_node().getReleaseBallCoord(),
            std::make_shared<Coord>(Coord(0, 0)), ball.get_move_ball_node().getSpeed(),
        ball.get_render_node().getSize(), Size(3,ScreenResolution::HEIGHT),
        DeflectNode::Target::Border, ball.get_release_ball_node().getBaseSpeed());

        auto topBorder = new DeflectNode(ball.get_release_ball_node().getReleaseBallCoord(),
            std::make_shared<Coord>(Coord(4, 0)), ball.get_move_ball_node().getSpeed(),
        ball.get_render_node().getSize(), Size(ScreenResolution::WIDTH,3),
        DeflectNode::Target::Border, ball.get_release_ball_node().getBaseSpeed());

        auto rightBorder = new DeflectNode(ball.get_release_ball_node().getReleaseBallCoord(),
           std::make_shared<Coord>(Coord(ScreenResolution::WIDTH - 4, 4)), ball.get_move_ball_node().getSpeed(),
        ball.get_render_node().getSize(), Size(3, ScreenResolution::HEIGHT),
        DeflectNode::Target::Border, ball.get_release_ball_node().getBaseSpeed());
        
        systemManager->getDeflectSystem().addNode(whiteTileDeflectNode);
        systemManager->getDeflectSystem().addNode(platformDeflectNode);
        systemManager->getDeflectSystem().addNode(leftBorder);
        systemManager->getDeflectSystem().addNode(topBorder);
        systemManager->getDeflectSystem().addNode(rightBorder);
    }
    
};

#pragma once
#include <algorithm>
#include <vector>
#include "../nodes/DeflectNode.h"
#include "../utilities/Collider.h"

class SystemManager;

class DeflectSystem
{
public:
    void setSystemManager(SystemManager* systemManager)
    {
        this->systemManager = systemManager;
    }

    void addNode(DeflectNode* node)
    {
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::for_each(nodes.begin(), nodes.end(),[] (DeflectNode* node)
        {
            double aX1 = node->getBallCord()->getX();
            double aX2 = node->getBallCord()->getX() + node->getBallSize().getWeigth();
            double aY1 = node->getBallCord()->getY();
            double aY2 = node->getBallCord()->getY() + node->getBallSize().getHeigth();

            double bX1 = node->getDeflectTargetCord()->getX();
            double bX2 = node->getDeflectTargetCord()->getX() + node->getTargetSize().getWeigth();
            double bY1 = node->getDeflectTargetCord()->getY();
            double bY2 = node->getDeflectTargetCord()->getY() + node->getTargetSize().getHeigth();

            bool isCollideAbove = Collider::isCollideAbove(aX1, aX2, aY1, aY2, bX1, bX2, bY1, bY2);
            bool isCollideBelow = Collider::isCollideBelow(aX1, aX2, aY1, aY2, bX1, bX2, bY1, bY2);
            bool isCollideLeft = Collider::isCollideLeft(aX1, aX2, aY1, aY2, bX1, bX2, bY1, bY2);
            bool isCollideRight = Collider::isCollideRight(aX1, aX2, aY1, aY2, bX1, bX2, bY1, bY2);
            
            switch (isCollideAbove + isCollideBelow + isCollideLeft + isCollideRight)
            {
            case 0:
                return;
            case 1:
                if(isCollideAbove || isCollideBelow)
                {
                    node->setBallSpeed(node->getBallSpeed()->getX(), node->getBallSpeed()->getY() * -1);
                }
                else
                {
                    node->setBallSpeed(node->getBallSpeed()->getX() * -1, node->getBallSpeed()->getY());
                }
                break;
            case 2:
                node->setBallSpeed(node->getBallSpeed()->getX() * -1, node->getBallSpeed()->getY() * -1);
                break;
            }

            //if(node->getTarget() == DeflectNode::Target::Platform)
            //{
            //   increaseSpeed(node->getBallSpeed()->getX(), node->getBallSpeed()->getY(), node->getBaseSpeed());
            //}
            //else
            //{
            //   decreaseSpeed(node->getBallSpeed()->getX(), node->getBallSpeed()->getY(), node->getBaseSpeed());
            //}
        });
    }
    
private:
    SystemManager* systemManager;
    std::vector<DeflectNode*> nodes;

    static void increaseSpeed(double& speedX, double& speedY, double baseSpeed)
    {
        double signX = speedX > 0 ? 1: -1;
        double signY = speedY > 0 ? 1: -1;

        double absSpeedX = fabs(speedX);
        double absSpeedY = fabs(speedY);
        
        speedX = speedX + 15 * absSpeedX / 100 * signX;
        speedY = speedY + 15 * absSpeedY / 100 * signY;
        
        double absSpeed = absSpeedX + absSpeedY;
        double maxSpeed = 3 * baseSpeed;

        double propX = absSpeedX / absSpeed;
        double propY = absSpeedY / absSpeed;

        if(absSpeed > maxSpeed)
        {
            absSpeed = maxSpeed;

            double perccX = propX * 100/(propX + propY);
            double perccY = propY * 100/(propX + propY);

            speedX = perccX * absSpeed / 100;
            speedY = perccY * absSpeed / 100;

            speedX *=signX;
            speedY *=signY;

            if(speedX > 0 != signX > 0)
                speedX = speedX * -1;

            if(speedY >0 != signY > 0)
                speedY = speedY * -1;
        }
    }

    static void decreaseSpeed(double& speedX, double& speedY, double baseSpeed)
    {
        double signX = speedX > 0 ? 1: -1;
        double signY = speedY > 0 ? 1: -1;

        double absSpeedX = fabs(speedX);
        double absSpeedY = fabs(speedY);
        
        double decrX = 10 * absSpeedX / 100 * signX;
        double decrY = 10 * absSpeedY / 100 * signY;
        speedX -= decrX;
        speedY -= decrY;
        
        double absSpeed = absSpeedX + absSpeedY;
        double minAbsSpeed = 40 * baseSpeed / 100;
        
        double propX = absSpeedX / absSpeed;
        double propY = absSpeedY / absSpeed;

        if(absSpeed < minAbsSpeed)
        {
            absSpeed = minAbsSpeed;

            double perccX = propX * 100/(propX + propY);
            double perccY = propY * 100/(propX + propY);

            speedX = perccX * absSpeed / 100;
            speedY = perccY * absSpeed / 100;

            if(speedX > 0 != signX > 0)
                speedX = speedX * -1;

            if(speedY >0 != signY > 0)
                speedY = speedY * -1;
        }
    }
};

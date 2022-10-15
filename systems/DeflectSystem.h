#pragma once
#include <algorithm>
#include "../nodes/DeflectNode.h"
#include "../utilities/Collider.h"

class DeflectSystem
{
public:
    void addNode(std::string&& uuid, DeflectNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, DeflectNode> pair)
        {
            double aX1 = pair.second.getBallCord().getX();
            double aX2 = pair.second.getBallCord().getX() + pair.second.getBallSize().getWidth();
            double aY1 = pair.second.getBallCord().getY();
            double aY2 = pair.second.getBallCord().getY() +pair.second.getBallSize().getHeigth();

            double bX1 = pair.second.getDeflectTargetCord().getX();
            double bX2 = pair.second.getDeflectTargetCord().getX() + pair.second.getTargetSize().getWidth();
            double bY1 = pair.second.getDeflectTargetCord().getY();
            double bY2 = pair.second.getDeflectTargetCord().getY() + pair.second.getTargetSize().getHeigth();

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
                    pair.second.setBallSpeed(pair.second.getBallSpeed().getX(), pair.second.getBallSpeed().getY() * -1);
                }
                else
                {
                    pair.second.setBallSpeed(pair.second.getBallSpeed().getX() * -1, pair.second.getBallSpeed().getY());
                }
                break;
            case 2:
                pair.second.setBallSpeed(pair.second.getBallSpeed().getX() * -1, pair.second.getBallSpeed().getY() * -1);
                break;
            }
        });
    }
    
private:
    std::unordered_map<std::string, DeflectNode> nodes;

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

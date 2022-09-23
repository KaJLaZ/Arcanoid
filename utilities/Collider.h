#pragma once

class Collider
{
public:
    static bool isCollideAbove(double aX1, double aX2, double aY1,
        double aY2, double bX1, double bX2, double bY1, double bY2)
    {
        return aX2 > bX1 && aY2 > bY1 && aY2 < bY2 && aX1 < bX2 && aY1 < bY1 && aY1 < bY2;
    }

    static bool isCollideBelow(double aX1, double aX2, double aY1,
        double aY2, double bX1, double bX2,double bY1, double bY2)
    {
        return aX1 < bX2 && aY1 < bY2 && aY1 > bY1 &&aX2 > bX1 && aY2 > bY2 && aY1 > bY1;
    }

    static bool isCollideLeft(double aX1, double aX2, double aY1,
        double aY2,double bX1, double bX2, double bY1, double bY2)
    {
        return aX2 > bX1 && aX2 < bX2 && aY2 > bY1 && aX1 < bX1 && aX1 < bX2 && aY1 < bY2;
    }

    static bool isCollideRight(double aX1, double aX2, double aY1,
        double aY2, double bX1, double bX2, double bY1, double bY2)
    {
        return aX1 < bX2 && aX1 > bX1 && aY1 < bY2 &&aX2 > bX2 && aX2 > bX1 && aY2 > bY1;
    }
};

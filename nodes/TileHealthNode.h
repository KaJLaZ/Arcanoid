#pragma once
#include "../components/Coord.h"

class TileHealthNode
{
public:
    TileHealthNode(Coord* tileCord, int* tileHealth, WhiteTile* tile)
        : tileCord(tileCord),
        whiteTileHealth(whiteTileHealth),
        tile(tile) {}

    Coord* getTileCord()
    {
        return tileCord;
    }

    void setTileCoord(double x, double y)
    {
        this->tileCord->setX(x);
        this->tileCord->setY(y);
    }

     int* getWhiteTileHealth() const
    {
        return whiteTileHealth;
    }

    void decreaseHealth()
    {
        whiteTileHealth--;
    }

    WhiteTile* getTile()
    {
        return tile;
    }


private:
    Coord* tileCord;
    int* whiteTileHealth;
    WhiteTile* tile;
};

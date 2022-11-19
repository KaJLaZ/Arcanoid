#pragma once

#include <memory>
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Speed.h"

class SharedComponentHolder
{
public:
    SharedComponentHolder(std::shared_ptr<Coord> platform_coord, std::shared_ptr<Coord> ball_coord,
        std::shared_ptr<Coord> mouse_coord, std::shared_ptr<Coord> tile_coord,
        std::shared_ptr<Coord> left_border_tile_coord, std::shared_ptr<Coord> top_border_tile_coord,
        std::shared_ptr<Coord> right_border_tile_coord, std::shared_ptr<Speed> ball_speed,
        std::shared_ptr<FRKey> pressed_key)
        : platformCoord(std::move(platform_coord)),
          ballCoord(std::move(ball_coord)),
          mouseCoord(std::move(mouse_coord)),
          tileCoord(std::move(tile_coord)),
          leftBorderTileCoord(std::move(left_border_tile_coord)),
          topBorderTileCoord(std::move(top_border_tile_coord)),
          rightBorderTileCoord(std::move(right_border_tile_coord)),
          ballSpeed(std::move(ball_speed)),
          pressedKey(std::move(pressed_key)){}

    std::shared_ptr<Coord> getPlatformCoord()
    {
        return platformCoord;
    }

    std::shared_ptr<Coord> getBallCoord()
    {
        return ballCoord;
    }

    std::shared_ptr<Coord> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<Coord> getTileCoord()
    {
        return tileCoord;
    }

    std::shared_ptr<Coord> getLeftBorderTileCoord()
    {
        return leftBorderTileCoord;
    }

    std::shared_ptr<Coord> getTopBorderTileCoord()
    {
        return topBorderTileCoord;
    }

    std::shared_ptr<Coord> getRightBorderTileCoord()
    {
        return rightBorderTileCoord;
    }

    std::shared_ptr<Speed> getBallSpeed()
    {
        return ballSpeed;
    }

    std::shared_ptr<FRKey> getPressedKey()
    {
        return pressedKey;
    }

private:
    std::shared_ptr<Coord> platformCoord;
    std::shared_ptr<Coord> ballCoord;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<Coord> tileCoord;
    std::shared_ptr<Coord> leftBorderTileCoord;
    std::shared_ptr<Coord> topBorderTileCoord;
    std::shared_ptr<Coord> rightBorderTileCoord;
    std::shared_ptr<Speed> ballSpeed;
    std::shared_ptr<FRKey> pressedKey;
};

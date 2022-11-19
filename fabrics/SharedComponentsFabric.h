#pragma once
#include <memory>
#include "../Framework.h"
#include "../components/Coord.h"
#include "../components/Speed.h"
#include "../holders/ConfigsHolder.h"

class SharedComponentsFabric
{
public:
    SharedComponentsFabric(std::shared_ptr<config::ConfigsHolder> configs_holder, ScreenResolution screen_resolution)
        : configsHolder(std::move(configs_holder)), screenResolution(std::move(screen_resolution)){}

    std::shared_ptr<Coord> createPlatformCoord()
    {
        return std::make_shared<Coord>(Coord(configsHolder->getPlatformConfig().posX, configsHolder->getPlatformConfig().posY));
    }

    std::shared_ptr<Coord> createBallCoord()
    {
        return std::make_shared<Coord>(Coord(configsHolder->getBallConfig().posX, configsHolder->getBallConfig().posY));
    }

    std::shared_ptr<Coord> createMouseCoord()
    {
        return std::make_shared<Coord>(Coord(0, 0));
    }

    std::shared_ptr<Coord> createWhiteTileCoord()
    {
        return std::make_shared<Coord>(Coord(configsHolder->getWhiteTileConfig().posX, configsHolder->getWhiteTileConfig().posY));
    }

    std::shared_ptr<Coord> createLeftBorderTileCoord()
    {
        return std::make_shared<Coord>(Coord(0,0));
    }

    std::shared_ptr<Coord> createTopBorderTileCoord()
    {
        return std::make_shared<Coord>(Coord(11,0));
    }

    std::shared_ptr<Coord> createRightBorderTileCoord()
    {
        return std::make_shared<Coord>(Coord(screenResolution.width - 11, 11));
    }

    std::shared_ptr<Speed> createBallSpeed()
    {
        return std::make_shared<Speed>(Speed(configsHolder->getBallConfig().speedX, configsHolder->getBallConfig().speedY));
    }

    std::shared_ptr<FRKey> createPressedKey()
    {
        return std::make_shared<FRKey>(FRKey::UP);
    }

private:
    std::shared_ptr<config::ConfigsHolder> configsHolder;
    ScreenResolution screenResolution;
};

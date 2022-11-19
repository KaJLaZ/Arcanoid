#pragma once
#include "SharedComponentsFabric.h"
#include "../holders/ConfigsHolder.h"
#include "../holders/SharedComponentHolder.h"
#include "../utilities/ScreenResolution.h"

using namespace config;

class HoldersFabric
{
public:
    ConfigsHolder createConfigHolder(ScreenResolution resolution)
    {
        return {ConfigLoader(ConfigResolutionAdjuster(resolution))};
    }

    SharedComponentHolder createSharedComponentHolder(SharedComponentsFabric& sharedComponentsFabric)
    {
        return {
            sharedComponentsFabric.createPlatformCoord(),
            sharedComponentsFabric.createBallCoord(),
            sharedComponentsFabric.createMouseCoord(),
            sharedComponentsFabric.createWhiteTileCoord(),
            sharedComponentsFabric.createLeftBorderTileCoord(),
            sharedComponentsFabric.createTopBorderTileCoord(),
            sharedComponentsFabric.createRightBorderTileCoord(),
            sharedComponentsFabric.createBallSpeed(),
            sharedComponentsFabric.createPressedKey()};
    }
};

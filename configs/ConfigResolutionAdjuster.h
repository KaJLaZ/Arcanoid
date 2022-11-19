#pragma once

#include "../utilities/ScreenResolution.h"
#include "entities/BallConfig.h"
#include "entities/PlatformConfig.h"
#include "entities/WhiteTileConfig.h"

namespace config
{
    class ConfigResolutionAdjuster
    {
    public:
        ConfigResolutionAdjuster(ScreenResolution resolution): resolution(resolution){}

        PlatformConfig getAdjustedPlatformConfig(PlatformConfig&& config)
        {
            return PlatformConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.moveDistance)};
        }

        BallConfig getAdjustedBallConfig(BallConfig&& config)
        {
            return BallConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.speedX),
                adjustByWidthRes(config.speedY),
                adjustByWidthRes(config.unreleasedMoveDistance),
                adjustByWidthRes(config.baseSpeed)};
        }

        WhiteTileConfig getAdjustedWhiteTileConfig(WhiteTileConfig&& config)
        {
            return WhiteTileConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.healthPoints};
        }
        
    private:
        ScreenResolution resolution;
        
        template<class T>
        T adjustByWidthRes(T& percentFromResolution)
        {
            return percentFromResolution * resolution.width / 100;
        }
        
        template<class T>
        int adjustByHeightRes(T& percentFromResolution)
        {
            return percentFromResolution * resolution.height / 100;
        }
    };
}

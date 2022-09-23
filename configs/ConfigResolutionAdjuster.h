#pragma once

#include "../utilities/ScreenResolution.h"
#include "entities/BallStartConfig.h"
#include "entities/PlatformStartConfig.h"
#include "entities/WhiteTileStartConfig.h"

namespace config
{
    class ConfigResolutionAdjuster
    {
    public:
        static PlatformStartConfig adjustPlatformConfig(PlatformStartConfig& config)
        {
            return PlatformStartConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.moveDistance)};
        }

        static BallStartConfig adjustBallConfig(BallStartConfig& config)
        {
            return BallStartConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.speedX),
                adjustByWidthRes(config.speedY),
                adjustByWidthRes(config.unreleasedMoveDistance),
                adjustByWidthRes(config.baseSpeed)};
        }

        static WhiteTileStartConfig adjustWhiteTileConfig(WhiteTileStartConfig& config)
        {
            return WhiteTileStartConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.healthPoints};
        }
        
    private:
        template<class T>
        static T adjustByWidthRes(T percentFromResolution)
        {
            return percentFromResolution * ScreenResolution::WIDTH / 100;
        }

        static int adjustByHeightRes(int percentFromResolution)
        {
            return percentFromResolution * ScreenResolution::HEIGHT / 100;
        }
    };
}

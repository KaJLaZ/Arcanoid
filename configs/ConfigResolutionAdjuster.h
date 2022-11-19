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
        static PlatformConfig adjustPlatformConfig(PlatformConfig& config)
        {
            return PlatformConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.moveDistance)};
        }

        static BallConfig adjustBallConfig(BallConfig& config)
        {
            return BallConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByWidthRes(config.speedX),
                adjustByWidthRes(config.speedY),
                adjustByWidthRes(config.unreleasedMoveDistance),
                adjustByWidthRes(config.baseSpeed)};
        }

        static WhiteTileConfig adjustWhiteTileConfig(WhiteTileConfig& config)
        {
            return WhiteTileConfig{config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.healthPoints};
        }
        
    private:
        template<class T>
        static T adjustByWidthRes(T& percentFromResolution)
        {
            return percentFromResolution * ScreenResolution::WIDTH / 100;
        }

        static int adjustByHeightRes(int& percentFromResolution)
        {
            return percentFromResolution * ScreenResolution::HEIGHT / 100;
        }
    };
}

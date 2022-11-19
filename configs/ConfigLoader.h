#pragma once
#include "ConfigResolutionAdjuster.h"
#include "../utilities/ConfigDeserializer.h"
#include "entities/BallConfig.h"
#include "entities/PlatformConfig.h"
#include "entities/WhiteTileConfig.h"

namespace config
{
    class ConfigLoader
    {
    public:
        inline static const char* PLATFORM_CONFIG_FILE_PATH = "resources/configs/PlatformConfig.json";
        inline static const char* WHITE_TILE_CONFIG_FILE_PATH = "resources/configs/WhiteTileConfig.json";
        inline static const char* BALL_CONFIG_FILE_PATH = "resources/configs/BallConfig.json";

        ConfigLoader(ConfigResolutionAdjuster adjuster): resolutionAdjuster(adjuster){}

        PlatformConfig loadPlatformConfig()
        {
            return resolutionAdjuster.getAdjustedPlatformConfig(
                ConfigDeserializer::deserializeConfig<PlatformConfig>(PLATFORM_CONFIG_FILE_PATH));
        }

        WhiteTileConfig loadWhiteTileConfig()
        {
            return resolutionAdjuster.getAdjustedWhiteTileConfig(
                ConfigDeserializer::deserializeConfig<WhiteTileConfig>(WHITE_TILE_CONFIG_FILE_PATH));
        }

        BallConfig loadBallConfig()
        {
            return resolutionAdjuster.getAdjustedBallConfig(
                ConfigDeserializer::deserializeConfig<BallConfig>(BALL_CONFIG_FILE_PATH));
        }

        //TODO think about modification in oop style to not multiple mess
    
        private:
        ConfigResolutionAdjuster resolutionAdjuster;
    };
}

#pragma once
#include "../utilities/ConfigLoader.h"
#include "entities/BallConfig.h"
#include "entities/PlatformConfig.h"
#include "entities/WhiteTileConfig.h"

namespace config
{
    class ConfigsHolder
    {
    public:
        inline static const char* PLATFORM_CONFIG_FILE_PATH = "resources/configs/PlatformConfig.json";
        inline static const char* WHITE_TILE_CONFIG_FILE_PATH = "resources/configs/WhiteTileConfig.json";
        inline static const char* BALL_CONFIG_FILE_PATH = "resources/configs/BallConfig.json";
        
        PlatformConfig getPlatformConfig()
        {
            if(platformConfig == nullptr)
            {
                platformConfig = std::make_unique<PlatformConfig>(
                    ConfigLoader::loadConfig<PlatformConfig>(PLATFORM_CONFIG_FILE_PATH));
                
            }
            return *platformConfig;
        }

        WhiteTileConfig getWhiteTileConfig()
        {
            if(whiteTileConfig == nullptr)
            {
                whiteTileConfig = std::make_unique<WhiteTileConfig>(
                    ConfigLoader::loadConfig<WhiteTileConfig>(WHITE_TILE_CONFIG_FILE_PATH));
            }
            return *whiteTileConfig;
        }

        BallConfig getBallConfig()
        {
            if(ballConfig == nullptr)
            {
                ballConfig = std::make_unique<BallConfig>(
                    ConfigLoader::loadConfig<BallConfig>(BALL_CONFIG_FILE_PATH));
            }
            return *ballConfig;
        }

        //TODO think about modification in oop style to not multiple mess
    
    private:
        std::unique_ptr<PlatformConfig> platformConfig;
        std::unique_ptr<WhiteTileConfig> whiteTileConfig;
        std::unique_ptr<BallConfig> ballConfig;
    };
}

#pragma once
#include "../utilities/ConfigLoader.h"
#include "entities/BallStartConfig.h"
#include "entities/PlatformStartConfig.h"
#include "entities/WhiteTileStartConfig.h"

namespace config
{
    class ConfigsHolder
    {
    public:
        inline static const char* PLATFORM_CONFIG_FILE_PATH = "resources/configs/PlatformStartConfig.json";
        inline static const char* WHITE_TILE_CONFIG_FILE_PATH = "resources/configs/WhiteTileStartConfig.json";
        inline static const char* BALL_CONFIG_FILE_PATH = "resources/configs/BallStartConfig.json";
        
        PlatformStartConfig getPlatformStartConfig()
        {
            if(platformStartConfig == nullptr)
            {
                platformStartConfig = std::make_unique<PlatformStartConfig>(
                    ConfigLoader::loadConfig<PlatformStartConfig>(PLATFORM_CONFIG_FILE_PATH));
                
            }
            return *platformStartConfig;
        }

        WhiteTileStartConfig getWhiteTileStartConfig()
        {
            if(whiteTileStartConfig == nullptr)
            {
                whiteTileStartConfig = std::make_unique<WhiteTileStartConfig>(
                    ConfigLoader::loadConfig<WhiteTileStartConfig>(WHITE_TILE_CONFIG_FILE_PATH));
            }
            return *whiteTileStartConfig;
        }

        BallStartConfig getBallStartConfig()
        {
            if(ballStartConfig == nullptr)
            {
                ballStartConfig = std::make_unique<BallStartConfig>(
                    ConfigLoader::loadConfig<BallStartConfig>(BALL_CONFIG_FILE_PATH));
            }
            return *ballStartConfig;
        }

        //TODO think about modification in oop style to not multiple mess
    
    private:
        std::unique_ptr<PlatformStartConfig> platformStartConfig;
        std::unique_ptr<WhiteTileStartConfig> whiteTileStartConfig;
        std::unique_ptr<BallStartConfig> ballStartConfig;
    };
}

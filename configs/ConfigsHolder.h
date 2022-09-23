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
        
        PlatformStartConfig& getPlatformStartConfig()
        {
            if(platformStartConfig.spriteFilePath.empty())
            {
                platformStartConfig = ConfigLoader::loadConfig<PlatformStartConfig>(PLATFORM_CONFIG_FILE_PATH);
            }
            return platformStartConfig;
        }

        WhiteTileStartConfig& getWhiteTileStartConfig()
        {
            if(whiteTileStartConfig.spriteFilePath.empty())
            {
                whiteTileStartConfig = ConfigLoader::loadConfig<WhiteTileStartConfig>(WHITE_TILE_CONFIG_FILE_PATH);
            }
            return whiteTileStartConfig;
        }

        BallStartConfig& getBallStartConfig()
        {
            if(ballStartConfig.spriteFilePath.empty())
            {
                ballStartConfig = ConfigLoader::loadConfig<BallStartConfig>(BALL_CONFIG_FILE_PATH);
            }
            return ballStartConfig;
        }

        //TODO think about modification in oop style to not multiple mess
    
    private:
        PlatformStartConfig platformStartConfig;
        WhiteTileStartConfig whiteTileStartConfig;
        BallStartConfig ballStartConfig;
    };
}

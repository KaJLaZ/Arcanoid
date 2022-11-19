#pragma once

#include "../configs/ConfigLoader.h"
#include "../utilities/ConfigDeserializer.h"
#include "../configs/entities/BallConfig.h"
#include "../configs/entities/PlatformConfig.h"
#include "../configs/entities/WhiteTileConfig.h"

namespace config
{
    class ConfigsHolder
    {
    public:
        ConfigsHolder(ConfigLoader configLoader): configLoader(configLoader){}

        PlatformConfig getPlatformConfig()
        {
            if(platformConfig == nullptr)
            {
                platformConfig = std::make_unique<PlatformConfig>(configLoader.loadPlatformConfig());
            }
            return *platformConfig;
        }

        WhiteTileConfig getWhiteTileConfig()
        {
            if(whiteTileConfig == nullptr)
            {
                whiteTileConfig = std::make_unique<WhiteTileConfig>(configLoader.loadWhiteTileConfig());
            }
            return *whiteTileConfig;
        }

        BallConfig getBallConfig()
        {
            if(ballConfig == nullptr)
            {
                ballConfig = std::make_unique<BallConfig>(configLoader.loadBallConfig());
            }
            return *ballConfig;
        }

        //TODO think about modification in oop style to not multiple mess
    
    private:
        ConfigLoader configLoader;
        std::unique_ptr<PlatformConfig> platformConfig;
        std::unique_ptr<WhiteTileConfig> whiteTileConfig;
        std::unique_ptr<BallConfig> ballConfig;
    };
}

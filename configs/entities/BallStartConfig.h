#pragma once

#include <../include/json.hpp>

using nlohmann::json;

//TODO rename prefix Start from all configs
namespace config {
struct BallStartConfig
{
    std::string spriteFilePath;
    int posX;
    int posY;
    int width;
    int height;
    double speedX;
    double speedY;
    int unreleasedMoveDistance;
    double baseSpeed;
};
    
    void to_json(json& j, BallStartConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.posX}, {"y", setting.posY},
        {"width", setting.width}, {"height", setting.height},
          {"speedX", setting.speedX}, {"speedY", setting.speedY},
        {"unreleasedMoveDistance", setting.unreleasedMoveDistance},
        {"baseSpeed", setting.baseSpeed}};
    }

    void from_json(const json& j, BallStartConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.posX);
        j.at("y").get_to(setting.posY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("speedX").get_to(setting.speedX);
        j.at("speedY").get_to(setting.speedY);
        j.at("unreleasedMoveDistance").get_to(setting.unreleasedMoveDistance);
        j.at("baseSpeed").get_to(setting.baseSpeed);
    }
}

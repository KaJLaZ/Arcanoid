#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
struct PlatformConfig
{
    std::string spriteFilePath;
    int posX;
    int posY;
    int width;
    int height;
    int moveDistance;
};
    
    void to_json(json& j, PlatformConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.posX}, {"y", setting.posY},
        {"width", setting.width}, {"heigth", setting.height},
        {"moveDistance", setting.moveDistance}};
    }

    void from_json(const json& j, PlatformConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.posX);
        j.at("y").get_to(setting.posY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("moveDistance").get_to(setting.moveDistance);
    }
}

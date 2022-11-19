#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
struct WhiteTileConfig
{
    std::string spriteFilePath;
    int posX;
    int posY;
    int width;
    int height;
    int healthPoints;
};
    
    void to_json(json& j, WhiteTileConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.posX}, {"y", setting.posY},
        {"width", setting.width}, {"heigth", setting.height},
        {"healthPoints", setting.healthPoints}};
    }

    void from_json(const json& j, WhiteTileConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.posX);
        j.at("y").get_to(setting.posY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("healthPoints").get_to(setting.healthPoints);
    }
}

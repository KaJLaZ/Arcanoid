#pragma once
#include <fstream>
#include "../../json.hpp"

using nlohmann::json;

class ConfigLoader
{
public:
    template<class T>
    static T loadConfig(const char* path)
    {
        return json::parse(std::ifstream(path))
            .get<T>();
    }
};

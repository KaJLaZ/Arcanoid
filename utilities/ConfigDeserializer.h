#pragma once
#include <fstream>
#include "../dependency/include/json.hpp"

using nlohmann::json;

class ConfigDeserializer
{
public:
    template<class T>
    static T deserializeConfig(const char* path)
    {
        return json::parse(std::ifstream(path))
            .get<T>();
    }
};

#pragma once

#include "../dependency/include/uuid_v4.h"

class UUID
{
public:
    static std::string generate()
    {
        return UUIDv4::UUIDGenerator<std::mt19937_64>().getUUID().str();
    }
};

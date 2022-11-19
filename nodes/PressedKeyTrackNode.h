#pragma once

#include <memory>
#include "../Framework.h"

class PressedKeyTrackNode
{
public:
    PressedKeyTrackNode(std::shared_ptr<FRKey> pressedKey) : pressedKey(std::move(pressedKey)){}

    FRKey getPressedKey()
    {
        return *pressedKey;
    }

    void setPressedKey(FRKey key)
    {
        *pressedKey = key;
    }

private:
    std::shared_ptr<FRKey> pressedKey;
};

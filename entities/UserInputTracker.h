#pragma once
#include <string>

#include "../nodes/PressedKeyTrackNode.h"
#include "../nodes/MouseTrackNode.h"

class UserInputTracker
{
public:
    UserInputTracker(std::string uuid, MouseTrackNode mouseTrackNode, PressedKeyTrackNode pressedKeyTrackNode)
        : uuid(std::move(uuid)),
          mouseTrackNode(std::move(mouseTrackNode)),
          pressedKeyTrackNode(std::move(pressedKeyTrackNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    MouseTrackNode& getRenderNode()
    {
        return mouseTrackNode;
    }

private:
    std::string uuid;
    MouseTrackNode mouseTrackNode;
    PressedKeyTrackNode pressedKeyTrackNode;
};

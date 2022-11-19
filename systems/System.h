#pragma once
#include <string>

template<class N>
class System
{
    virtual void addNode(std::string&& uuid, N& node) = 0;
    
    virtual void process() = 0;
    
    virtual void removeNode(std::string key) = 0;
};

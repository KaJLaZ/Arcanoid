#pragma once
#include <algorithm>
#include <vector>
#include "../nodes/TileHealthNode.h"
#include "../managers/EntityManager.h"

class TileHealthSystem
{
public:
    /*void setEntityManager(EntityManager* entityManager)
    {
        this->entityManager = entityManager;
    }*/

    void setSysteManager(SystemManager* systemManager)
    {
        this->systemManager = systemManager;
    }
    
    void addNode(TileHealthNode& node)
    {
        nodes.emplace_back(node);
    }
    
    void process()
    {
        std::for_each(nodes.begin(), nodes.end(),[&] (TileHealthNode& node)
        {
            if(node.getWhiteTileHealth() == 0)
            {
      //          entityManager->removeWhiteTile();
            }
        });
    }
    
private:
    SystemManager* systemManager;
    std::vector<TileHealthNode> nodes;
};

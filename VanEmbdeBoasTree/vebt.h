#ifndef vebt_h
#define vebt_h

#include <iostream>
#include "cluster.h"
#include "summary.h"

class VanEmbedBoasTree
{
private:
    VanEmbedBoasTree *cluster;
    Summary *summary;
    int u;
    int min;
    int max = -1;

public:
    VanEmbedBoasTree()=default;
    VanEmbedBoasTree(int u)
    {
        this->u = u;
        this->cluster = new VanEmbedBoasTree[u];
    }

    VanEmbedBoasTree * getCluster(){
        return this-> cluster;
    }

    bool getRoot(){
        return summary->getBit();
    }
};

#endif
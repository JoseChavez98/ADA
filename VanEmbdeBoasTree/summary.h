#ifndef SUMMARY_H
#define SUMMARY_H

#include "vebt.h"
#include "cluster.h"

struct Node
{
    bool bit = false;
    Node *right;
    Node *left;
};

class Summary
{
private:
    Node *head;

public:
    Summary() = default;
    Summary(  VanEmbedBoasTree *veb)
    {
        // auto cluster = veb->getCluster();
        // for (int i = 0; i < (int)(math.sqrt(size) / 2); i++)
        // {
        //     if (cluster[i]->getRoot() or cluster[i + 1]->getRoot())
        //     {
        //         Node *newNode;
        //         newNode->right = cluster[i + 1];
        //         newNode->left = cluster[i];
        //     }
        // }
    }

    bool getBit()
    {
        return this->head->bit;
    }
};

#endif
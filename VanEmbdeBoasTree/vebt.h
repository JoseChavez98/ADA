#ifndef vebt_h
#define vebt_h

#include <iostream>
#include <climits>
#include <math.h>

class VanEmbedBoasTree
{
private:
    VanEmbedBoasTree **cluster;
    VanEmbedBoasTree *summary;
    int u;
    int min = INT_MAX;
    int max = -1;
    // bool arr[2];

    void insertEmpty(int x)
    {
        this->min = x;
        this->max = x;
    }

public:
    VanEmbedBoasTree() = default;
    VanEmbedBoasTree(int u)
    {
        this->u = u;

        if (this->u == 2)
        {
            this->cluster = nullptr;
            this->summary = nullptr;
            return;
        }
        int newSize = sqrt(this->u);
        this->cluster = new VanEmbedBoasTree *[newSize];
        for (int i = 0; i < newSize; i++)
        {
            VanEmbedBoasTree *newVeb = new VanEmbedBoasTree(newSize);
            cluster[i] = newVeb;
        }
        this->summary = new VanEmbedBoasTree(newSize);
    }

    void insert(int x)
    {
        if (this->min == INT_MAX)
            insertEmpty(x);

        else if (x < this->min)
        {
            swapMin(x);
            if (this->u > 2)
            {
                if (this->cluster[high(x)]->getMin() == INT_MAX)
                {
                    this->summary->insert(high(x));
                    this->cluster[high(x)]->insertEmpty(low(x));
                }
                else
                {
                    this->cluster[high(x)]->insert(low(x));
                }
            }
            if (x > this->max)
                this->max = x;
        }
    }

    void swapMin(int &x)
    {
        auto temp = this->min;
        this->min = x;
        x = temp;
    }

    int high(int x)
    {
        return (floor(x / sqrt(this->u)));
    }
    int low(int x)
    {
        return (x % (int)sqrt(this->u));
    }

    int getMin()
    {
        return this->min;
    }

    int getMax()
    {
        return this->max;
    }

    void print()
    {
        if (this->u == 2)
        {
            if (this->min == this->max)
            {
                std::cout << this->min << " ";
                return;
            }
            else
            {
                std::cout << this->min << " ";
                return;
            }
        }
        else
        {
            for (int i = 0; i < sqrt(this->u); i++)
            {
                this->cluster[i]->print();
            }
        }
        std::cout << this->max << " ";
        return;
    }
};

#endif
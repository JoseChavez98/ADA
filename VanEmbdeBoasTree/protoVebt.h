#ifndef protovebt_h
#define protovebt_h
#define ROOT true;

#include <iostream>
#include <climits>
#include <math.h>

class protoVanEmbedBoasTree
{
private:
    protoVanEmbedBoasTree **cluster;
    protoVanEmbedBoasTree *summary;
    int u;
    int min = -1;
    int max = -1;
    bool *arr;

    void insertEmpty(int x)
    {
        this->min = x;
        this->max = x;
    }

public:
    protoVanEmbedBoasTree() = default;
    explicit protoVanEmbedBoasTree(int u)
    {
        this->u = u;
        this->arr = new bool[this->u];
        for (int i = 0; i < this->u; i++)
        {
            this->arr[i] = false;
        }

        if (this->u == 2)
        {
            this->cluster = nullptr;
            this->summary = nullptr;
            return;
        }
        int newSize = sqrt(this->u);
        this->cluster = new protoVanEmbedBoasTree *[newSize];
        for (int i = 0; i < newSize; i++)
        {
            auto *newVeb = new protoVanEmbedBoasTree(newSize);
            this->cluster[i] = newVeb;
        }
        this->summary = new protoVanEmbedBoasTree(newSize);
    }

    void insert(int x)
    {
        this->arr[x] = true;
        if (this->min == -1)
            insertEmpty(x);

        else if (x < this->min)
            swapMin(x);

        if (this->u > 2)
        {
            if (this->cluster[high(x)]->getMin() == -1)
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

    int successor(int x)
    {
        if (this->u == 2)
        {
            if (x == 0 && this->max == 1)
                return 1;
            else
                return -1;
        }
        else if (this->min != -1 && x < this->min)
            return this->min;
        else
        {
            int max_low = this->cluster[high(x)]->getMax();

            if (max_low != -1 && low(x) < max_low)
            {
                auto offset = this->cluster[high(x)]->successor(low(x));
                return index(high(x), offset);
            }
            else
            {
                auto succ_cluster = this->summary->successor(high(x));
                if (succ_cluster == -1)
                    return -1;
                else
                {
                    int offset = this->cluster[succ_cluster]->getMin();
                    return index(succ_cluster, offset);
                }
            }
        }
    }

    bool find(int x)
    {
        return this->arr[x];
    }

    int index(int x, int y)
    {
        return x * sqrt(this->u) + y;
    }

    void swapMin(int &x)
    {
        auto temp = this->min;
        this->min = x;
        x = temp;
    }

    int high(int x)
    {
        return floor(x / sqrt(this->u));
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
};

#endif
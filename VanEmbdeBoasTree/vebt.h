#ifndef VEBT_H
#define VEBT_H

#define ROOT true;

#include <iostream>
#include <climits>
#include <cmath>
#include <math.h>

class VanEmbedBoasTree
{
private:
    VanEmbedBoasTree **cluster;
    VanEmbedBoasTree *summary;
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
    explicit VanEmbedBoasTree(int u)
    {
        int upper_square = pow(2, ceil(log2(u) / 2));
        int lower_square = pow(2, floor(log2(u) / 2));
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
        else
        {
            int newSize = upper_square;
            this->cluster = new VanEmbedBoasTree *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                auto *newVeb = new VanEmbedBoasTree(lower_square);
                this->cluster[i] = newVeb;
            }

            this->summary = new VanEmbedBoasTree(upper_square);
        }
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
        int root = pow(2, floor(log2(this->u) / 2));
        return x * root + y;
    }

    void swapMin(int &x)
    {
        auto temp = this->min;
        this->min = x;
        x = temp;
    }

    int high(int x)
    {

        int root = pow(2, floor(log2(this->u) / 2));
        return floor(x / root);
    }

    int low(int x)
    {
        int root = pow(2, floor(log2(this->u) / 2));
        return (x % root);
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
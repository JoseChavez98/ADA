#include <iostream>
#include <vector>
#include <climits>

typedef std::vector<long int> LIST;


int merge(LIST &set, int p, int q, int r, int &count)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L, *R;
    L = new int[n1 + 1];
    R = new int[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = set[p + i];
    }
    L[n1] = INT_MAX;

    for (int i = 0; i < n2; i++)
    {
        R[i] = set[q + i + 1];
    }
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            set[k] = L[i];
            i++;
        }
        else
        {
            set[k] = R[j];
            if(L[i]!=INT_MAX)
                count += (q-i-1);
            j++;
        }
    }
    delete L;
    delete R;
    return count;

}

int mergeSort(LIST &set, int p, int r,int &count)
{

    if (p < r)
    {
        int q = (p + r) / 2;
        count = mergeSort(set, p, q,count);
        count += mergeSort(set, q + 1, r,count);
        count+=merge(set, p, q, r,count);

    }
    return count;
}

int main()
{
    int count=0;
    LIST set;

    set.push_back(1);
    set.push_back(20);
    set.push_back(6);
    set.push_back(4);
    set.push_back(5);
    // set.push_back(6);

    mergeSort(set, 0, set.size() - 1,count);
    std::cout<<count;
    // for (int i = 0; i < set.size(); i++)
    // {
    //     std::cout << set[i] << " ";
    // }

    return 0;
}
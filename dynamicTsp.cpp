#include <iostream>
#include <vector>
#include <map>

// std::vector<std::vector<int>> allSets(int *arr,int size1, int size2){
//     std::vector<std::vector<int>>set;
//     std::vector<int> tuple;
//     for(int i=0;i<size;i++){
//         tuple.push_back(arr[i]);
//     }
// }

int min(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    std::map<int, std::vector<std::pair<std::vector<int>, int>>> index;

    int nodes[] = {1, 2, 3};

    int matrix[][4] = {
        {0, 1, 15, 6},
        {2, 0, 7, 3},
        {9, 6, 0, 12},
        {10, 4, 8, 0}};
    std::vector<int> sets[] = {{0}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};

    for (auto &set : sets)
    {
        for (auto &currentVertex : nodes)
        {
            int min = 1000000000;
            for (auto &key : set)
            {
                if (currentVertex == key)
                {
                    continue;
                }
                else
                {
                    if (set.size() < 2)
                    {
                        int value = matrix[key][currentVertex];
                        std::pair<std::vector<int>, int> newPair;
                        std::vector<int> newVector;
                        newVector.push_back(key);
                        newPair.first = newVector;
                        newPair.second = value;
                        index[currentVertex].push_back(newPair);
                        newVector.clear();
                    }
                    else
                    {
                        for (auto &vec : index[key])
                        {
                            for (auto &val : vec)
                            {
                                if (val ==  )
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
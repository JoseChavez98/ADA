#include <iostream>
#include <vector>

#define SIZE 4

int min(int a, int b)
{
    return (a > b) ? b : a;
}

void tsp(int graph[SIZE][SIZE], std::vector<bool> &v, int position, int n, int count, int cost, int &res)
{

    if (count == n && graph[position][SIZE])
    {
        res = min(res, cost + graph[position][0]);
        return;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (!v[i] && graph[position][i])
        {
            v[i] = true;
            tsp(graph, v, i, n, count + 1, cost + graph[position][i], res);
            v[i] = false;
        }
    }
};

int main()
{

    int graph[SIZE][SIZE] = {
        {2, 0, -1000, 0},
        {0, 0, 0, 4},
        {0, 4, 0, 0},
        {0, 0, 0, 8}};

    std::vector<bool> v(4);
    for (int i = 0; i < SIZE; i++)
        v[i] = false;

    v[0] = true;
    int ans = 1000000000;

    tsp(graph, v, 0, SIZE, 1, 0, ans);

    std::cout << ans;

    return 0;
}
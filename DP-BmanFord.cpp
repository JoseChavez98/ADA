#include <iostream>
#include <climits>

void bellManFord(int E[][3], int v, int e)
{

    int sum = 0;
    int *shortestPath = new int[v];
    for (int i = 1; i < v; i++)
        shortestPath[i] = INT_MAX;
    shortestPath[0] = 0;

    for (int relaxation = 0; relaxation < v - 1; relaxation++)
    {
        for (int edge = 0; edge < e; edge++)
        {
            sum = shortestPath[E[edge][0]] + E[edge][2];
            if (sum < shortestPath[E[edge][1]])
                shortestPath[E[edge][1]] = sum;
        }
    }

    for (int index = 0; index < v; index++)
    {
        std::cout << "vertex " << index << " : " << shortestPath[index] << '\n';
    }
}

int main()
{

    int v = 7;
    int e = 10;
    int graph[e][3] = {{0, 1, 6}, {0, 2, 5}, {0, 3, 5}, {1, 4, -1}, {2, 1, -2}, {2, 4, 1}, {3, 2, -2}, {3, 5, -1},{4,6,3},{5,6,3}};
    bellManFord(graph, v, e);

    return 0;
}
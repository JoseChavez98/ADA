#include <iostream>
#include <vector>
#include <list>

class Node
{
public:
    double up, down;

    Node() = default;
    bool operator==(Node const &node)
    {
        if (node.up == up && node.down == down)
            return true;
        return false;
    }
    bool operator<(Node const &node)
    {
        if (node.up / node.down > up / down)
            return true;
        return false;
    }
    bool operator>(Node const &node)
    {
        if (node.up / node.down < up / down)
            return true;
        return false;
    }
    Node operator+(Node const &node)
    {
        Node newNode{node.up + up, node.down + down};
        return newNode;
    }
};

std::string find(Node node)
{
    Node left{0, 1};
    Node middle{1, 1};
    Node right{1, 0};

    std::string path;

    while (true)
    {
        if (node == middle)
            return path;
        if (node < middle)
        {
            Node temp = middle;
            right = middle;
            middle = temp + left;
            path += 'L';
        }
        if (node > middle)
        {
            Node temp = middle;
            left = middle;
            middle = temp + right;
            path += 'R';
        }
    }
}

int main()

{

    double div1, div2;
    std::cin >> div1 >> div2;
    while (true)
    {
        if (div1 == 1 and div2 == 1)
            break;
        Node a1{div1, div2};
        std::cout << find(a1) << '\n';
        std::cin >> div1 >> div2;
    }
    return 0;
}
#include <iostream>

class Solution
{
public:
    int *p;
    void initM(int n)
    {
        p = new int[n+1];
        for (int i = 0; i < n+1; i++)
        {
            p[i] = -1;
        }
    }
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (p[n] != -1)
            return p[n];

        p[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return p[n];
    }
};

int stringToInteger(std::string input)
{
    return stoi(input);
}

int main()
{
    std::string line;
    while (getline(std::cin, line))
    {
        int n = stringToInteger(line);

        Solution a;
        a.initM(n);
        int ret = a.climbStairs(n);

        std::string out = std::to_string(ret);
        std::cout << out << std::endl;
    }
    return 0;
}
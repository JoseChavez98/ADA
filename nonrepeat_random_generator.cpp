#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <algorithm>

int main(){

    std::mt19937 rng(std::random_device{}());
    std::vector<int> vec(100);
    std::iota(begin(vec), end(vec), 0);
    std::shuffle(begin(vec), end(vec), rng);


    return 0;
}
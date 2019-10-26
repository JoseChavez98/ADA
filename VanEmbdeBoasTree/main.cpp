#include "vebt.h"
#include "protoVebt.h"

int main()
{

    VanEmbedBoasTree veb(8);
    veb.insert(2);
    veb.insert(4);
    veb.insert(5);
    veb.insert(6);

    protoVanEmbedBoasTree pveb(16);
    pveb.insert(2);
    pveb.insert(3);
    pveb.insert(4);
    pveb.insert(5);
    pveb.insert(7);
    pveb.insert(10);
    pveb.insert(11);

    std::cout << veb.successor(4) << '\n';
     std::cout << pveb.successor(7) << '\n';

    std::cout << veb.find(6) << '\n';
     std::cout << pveb.find(11) << '\n';

    return 0;
}
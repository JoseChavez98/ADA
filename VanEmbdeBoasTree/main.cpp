#include "vebt.h"

int main()
{

    VanEmbedBoasTree veb(16);  
    veb.insert(2);
    veb.insert(3);
    veb.insert(4);
    veb.insert(5);
    veb.insert(7);
    veb.insert(14);
    veb.insert(15);

   std::cout<<veb.successor(14);
    // veb.print();

    return 0;
}
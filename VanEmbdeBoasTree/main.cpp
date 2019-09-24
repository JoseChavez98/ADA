#include "vebt.h"

int main()
{

    VanEmbedBoasTree veb(16);  
    veb.insert(1);
    veb.insert(4);
    veb.insert(8);
    veb.insert(3);
    veb.insert(10);
    veb.print();

    return 0;
}
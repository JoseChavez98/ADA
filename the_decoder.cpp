#include <iostream>
#include <vector>

std::string decode(std::string linea){
    std::string new_string;
    for(auto &i : linea){
        new_string+=(i-7);
    }
    return new_string;
}

int main(){
    std::string a;

    while(std::cin>>a){
        std::cout<<decode(a)<<'\n';
    }
    return 0;
}
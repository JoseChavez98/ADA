#include <iostream>
#include <vector>
#include <array>
#include <fstream>

int cycle(int i) {
    int cont=0;
    while (true) {
        cont++;
        if (i == 1) {
            break;
        }
        if (i % 2 != 0) {
            i = (3 * i) + 1;
        } else {
            i = i / 2;
        }
    }
    return cont;
}

int main(){

    std::vector<std::array<int,3>> lista;
    std::array<int,3> arr{};
    int a,b;
    int aloj;
    while(std::cin>>a>>b){

        bool switchs=false;
        if(a>b && a>=0){
            int temp=a;
            a=b;
            b=temp;
            switchs=true;
        }
        int container=0;
        for(int i=a;i<=b;i++){
            aloj=cycle(i);
            if(aloj>container){
                container=aloj;
            }
        }
        if(switchs){
            arr[0]=b;
            arr[1]=a;
        }else{
            arr[0]=a;
            arr[1]=b;
        }
        arr[2]=container;
        std::cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<'\n';
        //lista.push_back(arr);
    }

    for(auto i: lista){
        for(auto j : i){
            std::cout<< j<< " ";
        }
        std::cout<<'\n';
    }


    return 0;

}
#include <iostream>

void rotate(int **square,int size){

}

int main(){

    int N,n;
    char **big_square;
    char **lil_square;
    std::cin>>N>>n;
    big_square=new char*[N];
    lil_square=new char*[n];

    for(int i=0;i<N;i++){
        big_square[i]=new char[N];
        for(int j=0;j<N;j++){
            std::cin>>big_square[i][j];
        }
    }

    for(int i=0;i<n;i++){
        lil_square[i]=new char[n];
        for(int j=0;j<n;j++){
            std::cin>>big_square[i][j];
        }
    }


    return 0;
}
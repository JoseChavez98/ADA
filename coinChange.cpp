#include <iostream>

int coinChange(int amount){
    int coins[]={1,3,5};
    int **p = new int*[4];

    for(int i=0;i<4;i++)
        p[i]=new int[amount+1];

    for(int i=0;i<amount+1;i++)
        p[0][i]= 0;

    for(int i=1;i<4;i++){
        for(int j=0;j<amount+1;j++){
            if(coins[i]<=j)
                p[i][j]=p[i-1][coins[i-1]]+;
        }
    }
    



}


int main(){

    std::cout<<coinChange(5);
    return 0;
}
#include <iostream>

int min(int a, int b){
    return (a<=b)? a : b;
}

int fewCoinChange(int n){
    int *arr= new int[n+1];
    arr[0]=0;
    for(int i=1;i<n+1;++i){
        arr[i]=n+1;
    }
    int coins[]={1,2,5};
    for(int i=1;i<n+1;i++){
        for(int j=0;j<3;j++){
            if(coins[j]<=i){
               arr[i]= min(arr[i-coins[j]]+1,arr[i]);
            }
        }
    }
    return arr[n];
}

int main(){

    std::cout<<fewCoinChange(11);

    return 0;
}
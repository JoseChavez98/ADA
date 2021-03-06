#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <random>

void PrintArray(int arr[],int arr_size){
    for(int i=0;i<arr_size;i++)
    {
        std::cout<<arr[i]<<'-';
    }
    std::cout<<'\n';
}

void Swap(int arr[],int index1, int index2){

    int exchange_var;exchange_var=arr[index2];arr[index2]=arr[index1];arr[index1]=exchange_var;


}

int PartitionArray(int arr[],int p,int r){

    int x = arr[r];
    int i = p-1;

    for(int j=p;j<=r-1;j++)
    {
        if(arr[j]<=x){

            i+=1;
            Swap(arr,i,j);

        }
    }

    Swap(arr,i+1,r);

    return i + 1;
}

int RandomizedPartition(int arr[] , int p, int r){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(p,r); // distribution in range [1, 6]

    int i = dist6(rng) ;
    Swap(arr,i,r);
    return PartitionArray(arr,p,r);
}

void RandomQuicksort(int arr[],int p,int r){

    if(p<r){

        int q = RandomizedPartition(arr,p,r);

        RandomQuicksort(arr,p,q-1);
        RandomQuicksort(arr,q+1,r);
    }
}

int main(){
    srand (time(NULL));
    //int arr_size = rand() % 10 + 1;
    int arr_size=8;
    //int *arr= new int[arr_size];
    int arr[]={2,8,7,1,3,5,6,4};

//    for(int i=0;i<arr_size;i++)
//    {
//        arr[i]=rand() % 30;
//    }

    PrintArray(arr,arr_size);

    RandomQuicksort(arr,0,arr_size-1);

    PrintArray(arr,arr_size);


    return 0;

}
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

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

void Quicksort(int arr[],int p,int r){

    if(p<r){

        int x = PartitionArray(arr,p,r);

        Quicksort(arr,p,x-1);
        Quicksort(arr,x+1,r);

    }
}

int main(){
    srand (time(NULL));
    int arr_size = rand() % 10 + 1;
    //int arr_size=8;
    int *arr= new int[arr_size];
    //int arr[]={2,8,7,1,3,5,6,4};

    for(int i=0;i<arr_size;i++)
    {
        arr[i]=rand() % 30;
    }

    PrintArray(arr,arr_size);

    Quicksort(arr,0,arr_size-1);

    PrintArray(arr,arr_size);


    return 0;

}
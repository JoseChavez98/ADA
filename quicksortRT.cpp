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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int PartitionArray(int arr[],int p,int r){

    int x = arr[r];
    int i = p-1;

    for(int j=p;j<=r-1;j++)
    {
        if(arr[j]<=x){

            i++;
            //Swap(arr,i,j);
            swap(&arr[i], &arr[j]);

        }
    }

    Swap(arr,i+1,r);

    return i + 1;
}



void Quicksort(int arr[],int p,int r){

    if(p<r){

        int q = PartitionArray(arr,p,r);

        Quicksort(arr,p,q-1);
        //Quicksort(arr,q+1,r);

        p = q + 1;

    }
}


int main(){
    srand (time(NULL));
    //int arr_size = rand() % 10 + 1;
    int arr_size=5;
    //int *arr= new int[arr_size];
    int arr[]={2,8,7,1,3};



    PrintArray(arr,arr_size);

    Quicksort(arr,0,arr_size-1);

    PrintArray(arr,arr_size);


    return 0;

}
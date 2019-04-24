#include <iostream>

void printArray(int array[],int size){
    for(int i=0 ; i<size ;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<'\n';
}
void Swap(int arr[],int index1, int index2){
    int  extra = arr[index1];
    arr[index1]= arr[index2];
    arr[index2]=extra;
}

int partitionArray(int arr[],int p, int r){
    int x = arr[r];
    int i = p-1;

    for(int j = p; j<r;j++){
        if(arr[j]<=x){
            i++;
            Swap(arr,i,j);
        }
    }
    Swap(arr,i+1,r);

    return i+1;
}
void quicksort( int arr[] , int p , int r){
if(p<r){
    int x = partitionArray(arr, p,r);

    quicksort(arr,p,x-1);
    quicksort(arr,x+1,r);
}
}

int main(){

    int arr[]={69,8,4,70,43,420,1};

    quicksort(arr,0,6);

    printArray(arr,7);
    return 0;
}
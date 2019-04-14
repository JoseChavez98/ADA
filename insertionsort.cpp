#include <iostream>

void inSort(int *arr,int size){
    for(int j=1;j<size;j++){
        int key=arr[j];
        int i = j - 1;
        while (i>-1 && arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}

int main(){
    int A[]={5,3,9,12,11,1,2,6};
    
    inSort(A,8);
    for(auto i : A){
        std::cout<<i<<" ";
    }    
    return 0;

}
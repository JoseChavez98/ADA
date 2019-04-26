#include <iostream>
#include <limits>
#include <chrono>
#include <numeric>
#include <random>
#include <vector>
#include <algorithm>

void PrintArray(int arr[],int arr_size){
    for(int i=0;i<arr_size;i++)
    {
        std::cout<<arr[i]<<'-';
    }
    std::cout<<'\n';
}

/*
 * InsertionSort
 * */
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

/*
 * MergeSort
 * */
void merge(int A[],int p,int q,int r){
    int INF = std::numeric_limits<int>::max();
    int n1= q-p+1;
    int n2= r-q;
    int *L,*R;
    L=new int[n1+1];
    R=new int[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[(q+1)+i];
    }
    L[n1]=INF;
    R[n2]=INF;
    int i=0;
    int j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
    delete L;
    delete R;
}

void mergesort(int A[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merge(A,p,q,r);
    }
}

/*
 * Quicksort
 * */
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

    int arr_size = 150;

    float Quickaverage = 0.0;
    float Mergeaverage = 0.0;
    float Insertionaverage = 0.0;
    int cont = 0;

    while(cont<100 ) {


        std::mt19937 rng(std::random_device{}());
        std::vector<int> vec(arr_size);
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), rng);

        int *arr = new int[arr_size];
        int *arr2 = new int[arr_size];
        int *arr3 = new int[arr_size];


        for (int i = 0; i < arr_size; i++) {
            int numero = vec[i];
            arr[i] = numero;
            arr2[i] = numero;
            arr3[i] = numero;
        }

        auto start2 = std::chrono::high_resolution_clock::now();
        mergesort(arr2, 0, arr_size - 1);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = end2 - start2;
        //std::cout << "MergeSort demora    : " << elapsed2.count() << " segundos" << '\n';
        Mergeaverage+=elapsed2.count();

        auto start3 = std::chrono::high_resolution_clock::now();
        Quicksort(arr3, 0, arr_size - 1);
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed3 = end3 - start3;
        //std::cout << "QuickSort demora    : " << elapsed3.count() << " segundos" << '\n';
        Quickaverage+=elapsed3.count();

        auto start = std::chrono::high_resolution_clock::now();
        inSort(arr,arr_size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        //std::cout<<"InsertionSort demora: "<<elapsed.count()<<" segundos"<<'\n';
        Insertionaverage+=elapsed.count();


        cont++;

    }

    std::cout<<"Quicksort average: "<<Quickaverage/20<<'\n';
    std::cout<<"Mergesort average: "<<Mergeaverage/20<<'\n';
    std::cout<<"Insertion average: "<<Insertionaverage/20<<'\n';


    return 0;
}

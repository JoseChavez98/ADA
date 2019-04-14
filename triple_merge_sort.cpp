#include <iostream>
#include <limits>

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
int main(){

    int A[]={3,6,1,98,45,2};
    mergesort(A,0,5);
    for(auto &i:A){
        std::cout<<i<<" ";
    }

    return 0;
}

#include <iostream>
#include <limits>
#include <vector>

long int merge(std::vector<long int> a, long int p, long int q,long int r) {

    long int inversiones = 0;

    long int derecha = p;
    long int mid = q+1;
    while((derecha <= q) && (mid<=r)){
        long int aa = a[derecha];
        long int bb = a[mid];
        if(a[derecha] > a[mid]){
            inversiones+=(q+1-derecha);
            mid++;
        } else {
            derecha++;
        }
    }

    long int tam1 = (r-p+1)/2 + (r-p+1)%2;
    long int tam2 = (r-p+1)/2;

    long int *left = new long int[tam1 + 1];
    long int *right = new long int[tam2 + 1];

    for(long int i = 0; i < tam1; i++) {
        left[i] = a[p+i];
    }
    for(long int i = 0; i < tam2; i++) {
        right[i] = a[p+tam1+i];
    }

    //colocamos sentinelas en las ultimas posiciones
    left[tam1] = std::numeric_limits<long int>::max();
    right[tam2] = std::numeric_limits<long int>::max();

    long int m = 0;
    long int n = 0;
    for(long int i = p; i <= r; i++) {
        if(left[m] <= right[n]) {
            a[i] = left[m]; m++;

        } else {
            a[i] = right[n]; n++;
        }
    }

    return inversiones;
}
long int mergesort(std::vector<long int> a, long int p , long int r) {
    if (p == r ) return 0;

    long int inversiones = 0;

    if(p < r ){
        long int q = (r+p)/2;
        inversiones += mergesort(a, p, q);
        inversiones += mergesort(a, q+1, r);
        inversiones += merge(a, p, q, r);
    }

    return inversiones;
}

int main(){

    std::vector<long int> vec;
    std::string palabra;
    long int inversion;

    while(std::cin>>palabra){
        if(palabra == "0"){break;}
        vec.push_back(stol(palabra));
    }

    inversion=mergesort(vec,0,vec.size());
    std::cout<<inversion;

    return 0;
}

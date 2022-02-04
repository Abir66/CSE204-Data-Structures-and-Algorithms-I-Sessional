#ifndef SORT_H
#define SORT_H

#include<cstdlib>

template<typename T>
void merge(T ara[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    T *left = new T[n1];
    T *right = new T[n2];
    for(int i = 0; i<n1; i++) left[i] = ara[p+i];
    for(int i = 0; i<n2; i++) right[i] = ara[q+1+i];

    int i=0,j=0;
    for(int k = p; k<=r; k++){
        if(i >= n1) ara[k] = right[j++];
        else if(j>=n2) ara[k] = left[i++];
        else if(left[i]<=right[j]) ara[k] = left[i++];
        else ara[k] = right[j++];
    }
    delete[] left;
    delete[] right;
}

template<typename T>
void mergeSort(T ara[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(ara,p,q);
        mergeSort(ara,q+1,r);
        merge(ara,p,q,r);
    }
}


template<typename T>
void insertionSort(T ara[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T x = ara[i];
        int j = i - 1;
 
        while (j >= 0 && ara[j] > x)
        {
            ara[j + 1] = ara[j];
            j = j - 1;
        }
        ara[j + 1] = x;
    }
}

template<typename T>
int partition(T ara[], int p, int r){
    T x = ara[r];
    int i = p-1;
    for(int j = p; j<r; j++){
        if(ara[j]<=x){
            i++;
            std::swap(ara[i],ara[j]);
        }
    }
    std::swap(ara[i+1], ara[r]);
    return i+1;
}

template<typename T>
int randomizedPartition(T ara[], int p, int r){
    int i = p + std::rand() % (r-p+1);
    std::swap(ara[i], ara[r]);
    return partition(ara,p,r);
}

template<typename T>
void quickSort(T ara[], int p, int r){
    if(p<r){
        int q = partition(ara,p,r);
        quickSort(ara,p,q-1);
        quickSort(ara,q+1,r);
    }
}

template<typename T>
void randomizedQuickSort(T ara[], int p, int r){
    if(p<r){
        int q = randomizedPartition(ara,p,r);
        randomizedQuickSort(ara,p,q-1);
        randomizedQuickSort(ara,q+1,r);
    }
}

#endif
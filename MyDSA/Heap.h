#ifndef HEAP_H
#define HEAP_H

#include<vector>
template<typename T>
class Heap{
    public:
    T* ara;
    int sz = 0;

    void heapify(int i){ //percolate Down
        int left = i<<1;
        int right = left | 1;
        int largest = i;

        if(left <= sz && ara[left]>ara[largest]) largest = left;
        if(right <= sz && ara[right]>ara[largest]) largest = right;

        if(largest != i){
            std::swap(ara[i], ara[largest]);
            heapify(largest);
        }  
    }

    void prelocateUP(int child){
        int parent = child>>1;
        if(parent < 1) return;
        if(ara[parent] >= ara[child]) return;
        std::swap(ara[parent], ara[child]);
        prelocateUP(parent);
    }

public:
    
    Heap(int n){ ara = new T[n+1]; }
    Heap(std::vector<T> &v){
        sz = v.size();
        ara = new T[sz + 1];
        for(int i = 0; i<sz; i++) ara[i+1] = v[i];
        for(int i = sz/2; i>0; i--) heapify(i);
    }

    void insert(int n){
        ara[++sz] = n;
        prelocateUP(sz);
    }

    int deleteKey(){
        int root = ara[1];
        ara[1] = ara[sz];
        heapify(1);
        sz--;
        return root;
    }

    int size(){return sz;}

    int getMax() {return ara[1];}

    ~Heap(){delete [] ara;}
};

template<typename T>
void heapsort(std::vector<T>&v){
    Heap<T> h(v);
    for(int i=0; i<v.size();i++) v[i] = h.deleteKey();
}

#endif
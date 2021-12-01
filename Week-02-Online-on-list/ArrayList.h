#ifndef ARRAYLIST2_H
#define ARRAYLIST2_H

#include "List.h"

template <typename T>
class ArrayList : public List<T>
{
    int chunckSize;
    int memSize;
    int listSize;
    int curr;
    T *ara;

    void resize(){
        memSize += chunckSize;
        T* newAra = new T[memSize];
        for(int i=0; i<listSize; i++) newAra[i] = ara[i];
        delete[] ara;
        ara = newAra;
    }

public:

    ArrayList(int x = 5){
        listSize = 0;
        chunckSize = memSize = x;
        ara = new T[memSize];
        curr = 0;
    }

    ArrayList(T list[], int k, int x = 5){
        listSize = k;
        chunckSize = x>k ? x : k;
        memSize = chunckSize;
        ara = new T[memSize];
        for(int i=0; i<listSize; i++) ara[i] = list[i];
        curr = 0;
    }

    

    // Clear contents from the list, to make it empty.
    void clear(){
        delete [] ara;
        curr = 0;
        ara = nullptr;
        listSize = 0;
        memSize = 0;
    }

    // Inserts an element at the current location.               
    void insert(const T &item){
        if(ara == nullptr) resize();
        if (listSize == memSize) resize();
        for (int i=listSize-1; i>=curr; i--) ara[i+1] = ara[i];
        ara[curr] = item;
        listSize++;
    }

    // Appends an element at the end of the list.
    void append(const T &item){
        if(ara == nullptr) resize();
        if (listSize == memSize) resize();
        ara[listSize++] = item;
    }
    
    // Remove and return the current element
    T remove(){
        std::cout<<curr<<" "<<listSize<<std::endl;
        T item = ara[curr];
        for(int i = curr; i < listSize-1; i++) ara[i] = ara[i+1];
        if(curr==listSize-1 && curr!=0){curr--;}
        listSize--;
        return item;
    }                 
    
    // Set the current position to the start of the list
    void moveToStart() { curr = 0; }         
    
    // Set the current position to the end of the list
    void moveToEnd() { curr = listSize-1; }          

    // Move the current position one step left. No change if already at the beginning
    void prev() { if (curr > 0) curr--; }

    // Move the current position one step right. No change if already at the end.
    void next() { if (curr < listSize-1) curr++; }

    // Return the number of elements in the list.
    int length() { return listSize; }

    // Return the position (in the list) of the current element.
    int currPos() { return curr; }

    // Set current position.
    void moveToPos(int pos) { curr = pos; }

    // Return the current element.
    T getValue() { return ara[curr]; }

    // Search returns the position of the element item or -1 if not found
    int Search(const T &item)
    {
        for (int i = 0; i < listSize; i++)
        {
            if (ara[i] == item)
                return i;
        }
        return -1;
    }


    void update(const T &item){
        ara[curr] = item;
    }

    void duplicate(){
        insert(getValue());
    }

    // Destructor. Deallocate memory
    ~ArrayList()
    {
        delete[] ara;
    }
};

#endif
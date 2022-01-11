#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include"Queue.h"
#include <iostream>

template <typename T>
class ArrayQueue : public Queue<T>
{
    int memSize;
    int front;
    int rear;
    int size;
    bool providedArray = false;
    T *array;

    void resize()
    {
        // T *newArray = new T[arraySize + chunckSize];
        T *newArray = new T[memSize * 2];
        int i,j;
        for(i = front, j = 1; j<=size ; i++, j++){
            newArray[j] = array[i%memSize];
        }
        front = 1;
        rear = size;
        memSize *= 2;
        if(!providedArray) delete[] array;
        array = newArray;
    }

public:

    ArrayQueue(int arraySize = 50){
        memSize = arraySize;
        array = new T[memSize];
        front = 1;
        rear = 0;
        size = 0;
    }

    ArrayQueue(T* array, int memSize){
        this->memSize = memSize;
        this->array = array;
        front = 1;
        rear = 0;
        size = 0;
        providedArray = true;
    }

    // Base destructor
    ~ArrayQueue() { clear(); }

    // Reinitialize the queue, i.e., make it (logically) empty queue.
    // <> means an empty queue. Clear allocated memory if the programming language permits.
    void clear(){
        size = 0;
        front = 1;
        rear = 0;
        if(!providedArray) delete[] array;
        array = nullptr;
    }

    // Enqueue an element.
    void enqueue(const T &item){
        if(array == nullptr) array = new T[memSize];
        if(size == memSize) resize();
        rear = (rear+1) % memSize;
        array[rear] = item;
        size++;
    }

    // Dequeue an element.
    T dequeue(){
        T it = array[front];
        front = (front+1)%memSize;
        size--;
        return it;
        
    }

    // Return the number of elements in the queue.
    int length(){ return size; }

    // Return the front element.
    T frontValue(){ return array[front]; }

    // Return the rear element
    T rearValue(){ return array[rear]; }

    // Return the rear element which has left the queue.
    T leaveQueue(){
        T it = array[rear];
        rear = (rear-1)%memSize;
        size--;
        return it;
        
    }

    // void print(){
    //     for(int i = 0; i<memSize; i++) std::cout<<array[i]<<" ";
    //     std::cout<<std::endl;
    // }
};

#endif
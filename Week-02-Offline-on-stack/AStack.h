#ifndef ASTACK_H
#define ASTACK_H

#include "Stack.h"
#include <assert.h>
#include <iostream>

template <typename T>
class AStack : public Stack<T>
{

    T *stackArray;
    int top;
    int direction = 1;
    int arraySize;
    bool shared = false;

    void resize()
    {
        // T *newArray = new T[arraySize + chunckSize];
        T *newArray = new T[arraySize * 2];
        int offset = direction == 1 ? 0 : arraySize;
        for (int i = 0; i < arraySize; i++) newArray[offset + i] = stackArray[i];
        top += offset;

        delete[] stackArray;
        stackArray = newArray;
        // arraySize += chunckSize;
        arraySize *= 2;
    }

public:
    AStack(int x = 100, int direction = 1)
    {
        arraySize = x;
        setDirection(direction);
        stackArray = new T[arraySize];
    }

    AStack(T* ara, int size, int direction = 1, bool shared = false){
        stackArray = ara;
        arraySize = size;
        setDirection(direction);
        this->shared = shared;
    }

    ~AStack(){
        if(!shared) delete[] stackArray;
    }

    // Reinitialize the stack, i.e., make it (logically) empty stack
    void clear()
    {
        top = direction == 1 ? 0 : arraySize - 1;
        //delete[] stackArray;
        //arraySize = 0;
        // stackArray = nullptr;
    }

    // Pushes an element.
    void push(const T &item)
    {
        if (length() == arraySize) resize();
        stackArray[top] = item;
        top += direction;
    }

    // Pop an element.
    T pop()
    {
        return stackArray[top -= direction];
    }

    // Return the number of elements in the list.
    int length() const
    {
        return direction == 1 ? top : arraySize - 1 - top;
    }

    // Return the current element
    const T &topValue() const
    {
        return stackArray[top - direction];
    }

    // Sets the direction of growth of an empty array based stack
    void setDirection(int direction)
    {
        this->direction = direction;
        top = direction == 1 ? 0 : arraySize - 1;
    }

};

#endif
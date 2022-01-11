#ifndef OUTERSTACK_H
#define OUTERSTACK_H

#include "AStack.h"



template <typename T>
class OuterStack : public Stack<T>
{

    AStack<AStack<T>*>* stacks;
    int size;
    int memSize;
    int defaultSize;
    int dir;
    bool providedArray = false;

    void resize()
    {
        //std::cout<<"overflow"<<std::endl;
        AStack<T>* stck = new AStack<T>(defaultSize,dir);
        stacks->push(stck);
        memSize += defaultSize;
    }

public:
    OuterStack(int x = 100, int direction = 1)
    {
        stacks = new  AStack<AStack<T>*>(1);
        AStack<T>* stck = new AStack<T>(x,direction);
        stacks->push(stck);
        size = 0;
        defaultSize = memSize = x;
        dir = direction;
    }

   OuterStack(T* ara, int x, int direction = 1){
        providedArray = true;
        stacks = new  AStack<AStack<T>*>(1);
        AStack<T>* stck = new AStack<T>(ara,x,direction);
        stacks->push(stck);
        size = 0;
        defaultSize = memSize = x;
        dir = direction; 
    }

    ~OuterStack(){
        clear();
    }

    // Reinitialize the stack, i.e., make it (logically) empty stack
    void clear()
    {
       while (stacks->length() > 0)
        {
            AStack<T>* stck = stacks->pop();
            delete stck;
        }
        size = 0;
        memSize = 0;
        if(providedArray) return;
        delete stacks;
        stacks = nullptr;
    }

    // Pushes an element.
    void push(const T &item)
    {
        if(stacks == nullptr) stacks = new  AStack<AStack<T>*>(1);
        else if (size == memSize) {std::cout<<"overflow"<<std::endl;}
        if (size == memSize) resize();
        stacks->topValue()->push(item);
        //std::cout<<stacks->topValue()->topValue();
        size++;
    }

    // Pop an element.
    T pop()
    {
        T item = stacks->topValue()->pop();
        if(stacks->topValue()->length() == 0){
            AStack<T>* stck = stacks->pop();
            delete stck; 
        }
        size--;
        return item;
        
    }

    // Return the number of elements in the list.
    int length() const
    {
        return size;
    }

    // Return the current element
    const T &topValue() const
    {
        return stacks->topValue()->topValue();   
    }

    // Sets the direction of growth of an empty array based stack
    void setDirection(int direction)
    {
        if(size == 0) stacks->topValue()->setDirection(dir = direction);
        
    }


};

#endif
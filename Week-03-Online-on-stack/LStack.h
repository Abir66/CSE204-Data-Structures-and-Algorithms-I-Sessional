#ifndef LSTACK_H
#define LSTACK_H

#include "Stack.h"

template <typename T>
struct Node
{
    T element;
    Node *next;
    Node(Node *next = nullptr) { this->next = next; }
    Node(const T &val, Node *next = nullptr)
    {
        element = val;
        this->next = next;
    }
};

template <typename T>
class LStack : public Stack<T>
{
    Node<T>* top;
    int size;

public:
    LStack()
    {
        top = nullptr;
        size = 0;
    }

    ~LStack()
    {
        clear();
    }

    // Reinitialize the stack, i.e., make it (logically) empty stack
    void clear()
    {
        while(top!=nullptr){
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    // Pushes an element.
    void push(const T &item)
    {
        top = new Node<T>(item, top);
        size++;
    }

    // Pop an element.
    T pop()
    {
        T item = top->element;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
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
        return top->element;
    }

    // Sets the direction of growth of an empty array based stack
    // Has no meaning in Linked List based stack
    void setDirection(int direction){}

};

#endif
#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "Queue.h"
#include <assert.h>

template <typename T>
struct Node
{
    T element;
    Node *next, *prev;
    Node(Node *prev = nullptr, Node *next = nullptr ) { this->next = next; this->prev = prev;}
    Node(const T &val, Node *prev = nullptr, Node *next = nullptr )
    {
        element = val;
        this->next = next;
        this->prev = prev;
    }
};

template <typename T>
class LLQueue : public Queue<T>
{
    Node<T> *front, *rear;
    int size;

public:

    LLQueue(){
        front = rear = new Node<T>();
        size = 0;
    }

    // Base destructor
    ~LLQueue() { clear(); }

    // Reinitialize the queue, i.e., make it (logically) empty queue.
    // <> means an empty queue. Clear allocated memory if the programming language permits.
    void clear() { while(front->next != nullptr) leaveQueue(); }

    // Enqueue an element.
    void enqueue(const T &item)
    {
        rear = rear->next = new Node<T>(item,rear,nullptr);
        size++;
    }

    // Dequeue an element.
    T dequeue()
    {
        assert(size>0);
        Node<T>* temp = front->next;
        T item = temp->element;
        front->next = temp->next;
        if(rear == temp) rear = front;
        else temp->next->prev = front;
        delete temp;
        size--;
        return item;
    }

    // Return the number of elements in the queue.
    int length() { return size; }

    // Return the front element.
    T frontValue() { return front->next->element; }

    // Return the rear element
    T rearValue() { return rear->element; }

    // Return the rear element which has left the queue.
    T leaveQueue()
    {
        assert(size>0);
        Node<T>* temp = rear;
        T item = rear->element;
        rear = rear->prev;
        rear->next = nullptr;
        delete temp;
        size--;
        return item;
    }
};

#endif
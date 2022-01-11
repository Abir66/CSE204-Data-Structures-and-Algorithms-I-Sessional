#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{

    void operator=(const Queue &) {} // Protct assignment
    Queue(const Queue &) {}          // Protect copy constructor

public:
    Queue() {}                         // Default constructor
    virtual ~Queue() {}                // Base destructor
    virtual void clear() = 0;          //Reinitialize the queue, i.e., make it (logically) empty queue. <> means an empty queue. Clear allocated memory if the programming language permits.
    virtual void enqueue(const T &item) = 0; // Enqueue an element.
    virtual T dequeue() = 0;           // Dequeue an element.
    virtual int length() = 0;          // Return the number of elements in the queue.
    virtual T frontValue() = 0;        // Return the front element.
    virtual T rearValue() = 0;         // Return the rear element
    virtual T leaveQueue() = 0;        // Return the rear element which has left the queue.
};

template <typename T>
void printQueue(Queue<T> &q, char seperator = ' ', char openBracket = 0, char endBracket = 0){
    int len = q.length();
    if(openBracket!=0) std::cout<<openBracket;
    for(int i = 1; i<=len;i++){
        T it = q.dequeue();
        std::cout<<it;
        if(i<len) std::cout<<seperator;
        q.enqueue(it);
    }
    if(endBracket!=0) std::cout<<endBracket;
    std::cout<<std::endl;
}

#endif
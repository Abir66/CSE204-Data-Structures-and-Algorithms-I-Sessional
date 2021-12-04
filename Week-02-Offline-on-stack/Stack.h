#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{

    void operator=(const Stack &) {} //Protect assignment
    Stack(const Stack &) {}          //Protect copy constructor
public:
    Stack(){}                                      // Default constructor
    virtual ~Stack(){}                             // Base destructor
    virtual void clear() = 0;                     // Reinitialize the stack, i.e., make it (logically) empty stack
    virtual void push(const T &item) = 0;         // Pushes an element.
    virtual T pop() = 0;                          // Pop an element.
    virtual int length() const = 0;               // Return the number of elements in the list.
    virtual const T &topValue() const = 0;        // Return the current element
    virtual void setDirection(int direction) = 0; // Sets the direction of growth of an empty array based stack
};

template<typename T>
void printStack(Stack<T> &s, const char seperator = ' ', bool reverse = false){
    if(s.length()==0) return;
    if(s.length()==1){ std::cout<<s.topValue(); return;}
    T top = s.pop();
    if(reverse) {printStack(s,seperator, reverse); std::cout<<seperator<<top;}
    else {std::cout<<top<<seperator; printStack(s,seperator, reverse);}
    s.push(top);
}

#endif
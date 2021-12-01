#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"

template<typename T>
struct Node{
    T element;
    Node* next;
    Node(Node* next = nullptr) { this->next = next;}
    Node(const T& val, Node* next = nullptr) { element = val; this->next = next;}
};

template <typename T>
class LinkedList : public List<T>
{
    Node<T> *head, *tail, *curr;
    int size, currPosition;

    void init(){
        curr = tail = head = new Node<T>;
        size = 0;
        currPosition = 0;
    }

    void removeAll(){
        while(head != nullptr){
            curr = head;
            head = head->next;
            delete curr;
        }
        currPosition = 0;
    }

public:
    
    LinkedList(int dummyChunckSize = 0){
        init();
    }

    LinkedList(T ara[], int len, int dummyChunckSize = 0){
        init();
        for(int i=0; i<len; i++) append(ara[i]);
        curr = head;
        currPosition = 0;
    }
    
    // Clear contents from the list, to make it empty.
    void clear(){
        removeAll(); 
        init();
    }

    // Inserts an element at the current location.               
    void insert(const T &item){
        curr->next = new Node<T>(item, curr->next);
        if (tail == curr) tail = curr->next;
        size++;
    }

    // Appends an element at the end of the list.
    void append(const T &item){
        if (size == 0) tail->next = new Node<T>(item, nullptr);
        else{
            tail = tail->next;
            tail->next = new Node<T>(item, nullptr);
        }
        size++;
    }
    
    // Remove and return the current element
    T remove(){
        Node<T> *temp = curr->next;
        T val = temp->element;
        
        if(curr->next == tail) tail = curr;
        curr->next = curr->next->next;
        if(curr->next == nullptr) prev();
        delete temp;
        size --;
        return val;
    }                 
    
    // Set the current position to the start of the list
    void moveToStart() { curr = head; currPosition = 0; }         
    
    // Set the current position to the end of the list
    void moveToEnd() { curr = tail; currPosition = size!=0 ? size-1 : 0;}          

    // Move the current position one step left. No change if already at the beginning
    void prev() {
        if(curr==head) return;
        Node<T> *it = head;
        while(it->next != curr) it = it->next;
        curr = it;
        currPosition--;
    }

    // Move the current position one step right. No change if already at the end.
    void next() { 
        if (curr != tail) {
            curr = curr->next;
            currPosition++;
        }
    }

    // Return the number of elements in the list.
    int length() { return size; }

    // Return the position (in the list) of the current element.
    int currPos() { return currPosition; }

    // Set current position.
    void moveToPos(int pos) { 
        curr = head;
        for(int i = 0; i<pos; i++){
            curr = curr->next;
        } 
        currPosition = pos;
    }

    // Return the current element.
    T getValue() { return curr->next->element; }

    // Search returns the position of the element item or -1 if not found
    int Search(const T &item)
    {
        Node<T>*point = head->next;
        int pos = 0;
        while (point!= nullptr){
            if (point->element == item) return pos;
            point = point->next;
            pos++;
        }
        return -1;
    }

    // Destructor
    ~LinkedList() { removeAll();}
    
};

#endif
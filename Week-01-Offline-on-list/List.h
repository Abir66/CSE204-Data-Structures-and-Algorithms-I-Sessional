#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
private:
    void operator=(const List &) {}         // Protect assignment
    List(const List &) {}                   // Protect copy constructor
public:
    List(){}                                // Default constructor
    virtual void clear() = 0;               // Clear contents from the list, to make it empty.
    virtual void insert(const T &item) = 0; // Inserts an element at the current location.
    virtual void append(const T &item) = 0; // Appends an element at the end of the list.
    virtual T remove() = 0;                 // Remove and return the current element
    virtual void moveToStart() = 0;         // Set the current position to the start of the list
    virtual void moveToEnd() = 0;           // Set the current position to the end of the list
    virtual void prev() = 0;                // Move the current position one step left. No change if already at the beginning
    virtual void next() = 0;                // Move the current position one step right. No change if already at the end.
    virtual int length() = 0;               // Return the number of elements in the list.
    virtual int currPos() = 0;              // Return the position (in the list) of the current element.
    virtual void moveToPos(int pos) = 0;    // Set current position.
    virtual T getValue() = 0;               // Return the current element.
    virtual int Search(const T &item) = 0;  // Search returns the position of the element item or -1 if not found
};

#endif
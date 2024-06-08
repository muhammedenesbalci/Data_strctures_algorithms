#ifndef LINKEDLIST_H 
#define LINKEDLIST_H 

#include <iostream>

struct Node {
    int data;
    int key;
    Node* nextNode;
    Node* prevNode;
};

class LinkedList {
public:
    //add element beggining of the list
    virtual void insertion(int value, int key) = 0;

    //add element given key of the list
    virtual void update(int value, int key) = 0;

    //delete element beggining of the list
    virtual void deletion() = 0;

    //delete element given key of the list
    virtual void delete_element(int key) = 0;

    //search an elemet given key
    virtual Node* search(int key) const = 0;

    // Reverse List
    virtual void reverse() = 0;
    //display linked list
    virtual void display() const = 0;

    virtual ~LinkedList() = 0;
};

#endif 
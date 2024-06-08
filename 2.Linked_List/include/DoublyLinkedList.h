#ifndef DOUBLYLINKEDLIST_H 
#define DOUBLYLINKEDLIST_H 

#include "LinkedList.h"

class DoublyLinkedList : public LinkedList {
private:
    Node* head;
    static int size;
public:
    DoublyLinkedList(int value, int key);

    void insertion(int value, int key) override;
    void update(int value, int key) override;
    void deletion() override;
    void delete_element(int key) override;
    Node* search(int key) const override;
    void reverse() override;
    void display() const override;

    ~DoublyLinkedList() override;
};

#endif // DOUBLYLINKEDLIST_H
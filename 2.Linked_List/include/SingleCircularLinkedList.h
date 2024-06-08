#ifndef SINGLECIRCULARLINKEDLIST_H 
#define SINGLECIRCULARLINKEDLIST_H 

#include "LinkedList.h"

class SingleCircularLinkedList : public LinkedList {
private:
    Node* head;
    static int size;
public:
    SingleCircularLinkedList(int value, int key);

    void insertion(int value, int key) override;
    void update(int value, int key) override;
    void deletion() override;
    void delete_element(int key) override;
    Node* search(int key) const override;
    void reverse() override;
    void display() const override;

    ~SingleCircularLinkedList() override;
};

#endif // SINGLECIRCULARLINKEDLIST_H
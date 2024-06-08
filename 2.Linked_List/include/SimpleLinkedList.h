#ifndef SIMPLELINKEDLIST_H 
#define SIMPLELINKEDLIST_H 

#include "LinkedList.h"

class SimpleLinkedList : public LinkedList {
private:
    Node* head;
    static int size;
public:
    SimpleLinkedList(int value, int key);

    void insertion(int value, int key) override;
    void update(int value, int key) override;
    void deletion() override;
    void delete_element(int key) override;
    Node* search(int key) const override;
    void reverse() override;
    void display() const override;

    ~SimpleLinkedList() override;
};

#endif // SIMPLELINKEDLIST_H
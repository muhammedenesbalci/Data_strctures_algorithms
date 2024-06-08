#include <iostream>
#include "../include/SimpleLinkedList.h"
#include "../include/DoublyLinkedList.h"
#include "../include/SingleCircularLinkedList.h"

using namespace std;

void simpleLinkedList_ex() {
    cout << "\n\nSimple Linked List example ###########################################\n";
    LinkedList* simpleLinkedList = new SimpleLinkedList(0, 0);

    cout << "Insertion element beggining-----------------------------------------------\n";
    for (int i = 1; i < 11; ++i) {
        simpleLinkedList->insertion(i*10, i);
    }

    simpleLinkedList->display();

    cout << "\nDeletion element beggining-----------------------------------------------\n";
    for (int i = 0; i < 2; ++i) {
        simpleLinkedList->deletion();
    }

    simpleLinkedList->display();

    cout << "\nSearch an element-----------------------------------------------\n";
    simpleLinkedList->search(4);
    simpleLinkedList->search(5);
    simpleLinkedList->search(8);
    simpleLinkedList->search(11);
    simpleLinkedList->search(2);

    cout << "\nDelete an element-----------------------------------------------\n";
    simpleLinkedList->delete_element(6);
    simpleLinkedList->delete_element(8);
    simpleLinkedList->delete_element(5);
    simpleLinkedList->delete_element(9);
    simpleLinkedList->display();

    cout << "\nUpadte an element-----------------------------------------------\n";
    simpleLinkedList->update(9999, 7);
    simpleLinkedList->update(8888, 0);
    simpleLinkedList->display();

    cout << "\nReverse-----------------------------------------------\n";
    simpleLinkedList->reverse();

    cout << "\nDelete Classes -----------------------------------------------\n";
    delete simpleLinkedList;
}
void doublyLinkedList_ex() {
    cout << "\n\nDoubly Linked List example ###########################################\n";
    LinkedList* doublyLinkedList = new DoublyLinkedList(0, 0);

    cout << "Insertion element beggining-----------------------------------------------\n";
    for (int i = 1; i < 11; ++i) {
        doublyLinkedList->insertion(i*10, i);
    }

    doublyLinkedList->display();
    
    cout << "\nDeletion element beggining-----------------------------------------------\n";
    for (int i = 0; i < 2; ++i) {
        doublyLinkedList->deletion();
    }

    doublyLinkedList->display();
    
    cout << "\nSearch an element-----------------------------------------------\n";
    doublyLinkedList->search(4);
    doublyLinkedList->search(5);
    doublyLinkedList->search(8);
    doublyLinkedList->search(11);
    doublyLinkedList->search(2);
    

    cout << "\nDelete an element-----------------------------------------------\n";
    doublyLinkedList->delete_element(6);
    doublyLinkedList->delete_element(8);
    doublyLinkedList->delete_element(5);
    doublyLinkedList->delete_element(9);
    doublyLinkedList->display();
    
    
    cout << "\nUpadte an element-----------------------------------------------\n";
    doublyLinkedList->update(9999, 7);
    doublyLinkedList->update(8888, 0);
    doublyLinkedList->display();


    cout << "\nReverse-----------------------------------------------\n";
    doublyLinkedList->reverse();
    cout << "\nDelete Classes -----------------------------------------------\n";
    delete doublyLinkedList;
}
void singleCircularLinkedList_ex() {
    cout << "\n\nSingle Circular Linked List example ###########################################\n";
    LinkedList* singleCircularLinkedList = new SingleCircularLinkedList(0, 0);

    cout << "Insertion element beggining-----------------------------------------------\n";
    for (int i = 1; i < 11; ++i) {
        singleCircularLinkedList->insertion(i*10, i);
    }

    singleCircularLinkedList->display();
    
    
    cout << "\nDeletion element beggining-----------------------------------------------\n";
    for (int i = 0; i < 2; ++i) {
        singleCircularLinkedList->deletion();
    }

    singleCircularLinkedList->display();

    
    cout << "\nSearch an element-----------------------------------------------\n";
    singleCircularLinkedList->search(4);
    singleCircularLinkedList->search(5);
    singleCircularLinkedList->search(8);
    singleCircularLinkedList->search(11);
    singleCircularLinkedList->search(2);
    
    
    cout << "\nDelete an element-----------------------------------------------\n";
    singleCircularLinkedList->delete_element(6);
    singleCircularLinkedList->delete_element(8);
    singleCircularLinkedList->delete_element(5);
    singleCircularLinkedList->delete_element(9);
    singleCircularLinkedList->display();
    
    
    cout << "\nUpadte an element-----------------------------------------------\n";
    singleCircularLinkedList->update(9999, 7);
    singleCircularLinkedList->update(8888, 0);
    singleCircularLinkedList->display();


    cout << "\nReverse-----------------------------------------------\n";
    singleCircularLinkedList->reverse();
    
    cout << "\nDelete Classes -----------------------------------------------\n";
    delete singleCircularLinkedList;
}

int main() {
    //simpleLinkedList_ex();
    //doublyLinkedList_ex();
    singleCircularLinkedList_ex();
    return 0;
}

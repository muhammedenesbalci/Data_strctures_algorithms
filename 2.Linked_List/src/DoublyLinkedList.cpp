#include "../include/DoublyLinkedList.h"

int DoublyLinkedList::size = 1;

DoublyLinkedList::DoublyLinkedList(int value, int key) {
    this->head = new Node;
    this->head->data = value;
    this->head->key = key;
    this->head->nextNode = nullptr;
    this->head->prevNode = nullptr;
}

void DoublyLinkedList::insertion(int value, int key) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->key = key;
    newNode->nextNode = this->head;
    newNode->prevNode = nullptr;

    this->head->prevNode = newNode;
    this->head = newNode;

    DoublyLinkedList::size += 1;
}

void DoublyLinkedList::update(int value, int key) {
    Node* tempNode = this->search(key);

    if (tempNode != nullptr) {
        tempNode->data = value;
    } else {
        std::cout << "element added\n" << std::endl;
        this->insertion(value, key);
    }
}

void DoublyLinkedList::deletion() {
    if(size == 0 || size == 1) {
        std::cout << "can not delete an item size: " << this->size << std::endl;
    } else {
        Node* newHead = this->head->nextNode;
        newHead->prevNode = nullptr;
        delete this->head;

        this->head = newHead;
        DoublyLinkedList::size -= 1;
    }
}
void DoublyLinkedList::delete_element(int key) {
    Node* searchedNode = this->search(key);
    bool status = false;

    if (searchedNode != nullptr) {
        std::cout << "Deleted element || " << "key: " << searchedNode->key << " value: " << searchedNode->data << " ptr: " << searchedNode << " Prev Node: " << searchedNode->prevNode << " Next Node: " <<searchedNode->nextNode<<std::endl;
        status = true;
    } else{
        std::cout << "Element not found.\n";
        return;
    }

    // başta olma durumu
    if(status && (searchedNode->prevNode != nullptr)) {
        searchedNode->prevNode->nextNode = searchedNode->nextNode;
    } else if (status && (searchedNode->prevNode == nullptr)) {
        this->head = searchedNode->nextNode;
    }   

    // sonra olma durumu
    if (status && (searchedNode->nextNode != nullptr)) {
        searchedNode->nextNode->prevNode = searchedNode->prevNode;
    } else if (status && (searchedNode->nextNode == nullptr)) {
        searchedNode->prevNode->nextNode = nullptr;
    }

    DoublyLinkedList::size -= 1;
    delete searchedNode;
}

Node* DoublyLinkedList::search(int key) const {
    Node* tempHead = this->head;
    bool status = false;

    while(tempHead != nullptr) {
        if (tempHead->key == key) {
            status = true;
            std::cout << "Element found || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Prev Node: " << tempHead->prevNode << " Next Node: " <<tempHead->nextNode<<std::endl;
            break;
        }

        tempHead = tempHead->nextNode;
    }

    if (!status) {
        std::cout << "Element not found.\n";
        tempHead = nullptr;
    }

    return tempHead;
}

void DoublyLinkedList::reverse() {
    Node* tempHead = this->head;

    while (tempHead->nextNode != nullptr) {
        tempHead = tempHead->nextNode;
    } 

    while(tempHead != nullptr) {
        std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Prev Node: " << tempHead->prevNode << " Next Node: " <<tempHead->nextNode<<std::endl;
        tempHead = tempHead->prevNode;
    }
    std::cout << "-----------------------------------\n";
}
void DoublyLinkedList::display() const {
    std::cout << "Doubly Linked List size: "<< DoublyLinkedList::size << " --------------------\n";

    Node* tempHead = this->head;

    while(tempHead != nullptr) {
        std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Prev Node: " << tempHead->prevNode << " Next Node: " <<tempHead->nextNode<<std::endl;
        tempHead = tempHead->nextNode;
    }

    std::cout << "-----------------------------------\n";
}

DoublyLinkedList::~DoublyLinkedList(){
    std::cout << "Derived Class: Doubly Linked List Destructor Called\n";
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->nextNode;
        delete current; // Düğümü serbest bırak
        current = next; // Bir sonraki düğüme geç
    }

    head = nullptr; // Başlangıç noktasını null yap
    size = 0; // Liste boyutunu sıfırla
}
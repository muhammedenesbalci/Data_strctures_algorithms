#include "../include/SingleCircularLinkedList.h"

int SingleCircularLinkedList::size = 1;

SingleCircularLinkedList::SingleCircularLinkedList(int value, int key){
    this->head = new Node;
    this->head->data = value;
    this->head->key = key;
    this->head->nextNode = this->head;
}

void SingleCircularLinkedList::insertion(int value, int key){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->key = key;
    newNode->nextNode = this->head;

    Node* tempNode = this->head;

    while (tempNode->nextNode != this->head) {
        tempNode = tempNode->nextNode;
    }

    tempNode->nextNode = newNode;

    this->head = newNode;

    SingleCircularLinkedList::size +=1;
}

void SingleCircularLinkedList::update(int value, int key){
    Node* searched_element = this->search(key);
    if (searched_element!= nullptr) {
        std::cout << "element updated\n" << std::endl;

        searched_element->data = value;
    } else {
        std::cout << "element added\n" << std::endl;
        this->insertion(value, key);
    }
}

void SingleCircularLinkedList::deletion() {
    Node* newHead = this->head->nextNode;
    Node* tempNode = this->head;

    while(tempNode->nextNode != this->head) {
        tempNode = tempNode->nextNode;
    }

    tempNode->nextNode = newHead;

    delete this->head;
    this->head = newHead;
}

void SingleCircularLinkedList::delete_element(int key){
    if (!head) return;

    Node* current = head;
    Node* previous = nullptr;

    // Eğer silinecek düğüm baş düğümse ve tek düğüm varsa
    if (current->key == key && current->nextNode == head) {
        delete current;
        head = nullptr;
        return;
    }

    // Eğer silinecek düğüm baş düğümse ve birden fazla düğüm varsa
    if (current->key == key) {
        // Listenin son düğümünü bul
        while (current->nextNode != head) {
            current = current->nextNode;
        }
        Node* temp = head;
        head = head->nextNode;
        current->nextNode = head;
        delete temp;
        return;
    }

    // Diğer durumlar için
    current = head;
    do {
        previous = current;
        current = current->nextNode;
        if (current->key == key) {
            previous->nextNode = current->nextNode;
            delete current;
            return;
        }
    } while (current != head);
    
    std::cout << "Element not found.\n";
}

Node* SingleCircularLinkedList::search(int key) const {
    Node* tempHead = this->head;
    bool status = false;

    while (tempHead->nextNode != this->head) {
        if (tempHead->key == key) {
            std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
            status = true;
            break;
        }
        tempHead = tempHead->nextNode;
    }

    tempHead = tempHead->nextNode;
    if (tempHead->key == key) {
        std::cout << "Element Found || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
        status = true;
        return tempHead;
    }

    if (!status) {
        std::cout << "Element not found.\n";
        tempHead = nullptr;
    }

    return tempHead;
}

void SingleCircularLinkedList::reverse(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    Node* last = head;

    do {
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    } while (current != head);

    // Son düğümün nextNode'unu güncelle
    head->nextNode = prev;

    // Yeni head'i güncelle
    head = prev;

    this->display();
}

void SingleCircularLinkedList::display() const{
    std::cout << "Single Circular Linked List size: "<< SingleCircularLinkedList::size << " --------------------\n";

    Node* tempHead = this->head;

    while (tempHead->nextNode != this->head) {
        std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
        tempHead = tempHead->nextNode;
    }
    std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
    std::cout << "-----------------------------------\n";
}

SingleCircularLinkedList::~SingleCircularLinkedList(){
    std::cout << "Derived Class: Circular Linked List Destructor Called\n";

    Node* current = this->head;
    Node* next = nullptr;
    while (current->nextNode != this->head) {
        next = current->nextNode;
        delete current; // Düğümü serbest bırak
        current = next; // Bir sonraki düğüme geç
    }

    //Son düğümü serbest bırak.
    delete current;
    current = nullptr;

    head = nullptr; // Başlangıç noktasını null yap
    size = 0; // Liste boyutunu sıfırla
}
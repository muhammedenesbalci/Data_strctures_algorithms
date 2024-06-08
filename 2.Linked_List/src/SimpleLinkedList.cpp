#include "../include/SimpleLinkedList.h"

int SimpleLinkedList::size = 1;

SimpleLinkedList::SimpleLinkedList(int value, int key) : head(nullptr){
    this->head = new Node;
    this->head->data = value;
    this->head->nextNode = nullptr;
    this->head->key = key;
}

void SimpleLinkedList::insertion(int value, int key) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->key = key;
    new_node->nextNode = this->head;
    this->head = new_node;

    this->size += 1;
}

void SimpleLinkedList::update(int value, int key) {
    Node* searched_element = this->search(key);
    if (searched_element!= nullptr) {
        searched_element->data = value;
    } else {
        std::cout << "element added\n" << std::endl;
        this->insertion(value, key);
    }
}

void SimpleLinkedList::deletion(){
    if(size == 0 || size == 1) {
        std::cout << "can not delete an item size: " << this->size << std::endl;
    } else {
        Node* newHeadPtr = head->nextNode;
        delete head;
        head = newHeadPtr;
        SimpleLinkedList::size -= 1;
    } 
}

void SimpleLinkedList::delete_element(int key){
    Node* searchedNode = this->head;
    Node* prevNode = nullptr;
    bool status = false;

    while(searchedNode != nullptr) {
        if (searchedNode->key == key) {
            std::cout << "Deleted element ||" << "ptr: " << searchedNode << " value: " << searchedNode->data << " key: " << searchedNode->key << " Next Node: " << searchedNode->nextNode << std::endl;
            status = true;
            break;
        }
        prevNode = searchedNode;
        searchedNode = searchedNode->nextNode;  
    }

    if (!status) {
        std::cout << "Element not found.\n";
        return;
    } 

    if (prevNode != nullptr) {
        prevNode->nextNode = searchedNode->nextNode;
        
    } else {
         this->head = searchedNode->nextNode;
    }
    
    SimpleLinkedList::size -= 1;
    delete searchedNode;
}

Node* SimpleLinkedList::search(int key) const {
    Node* tempHead = this->head;
    bool status = false;

    while(tempHead != nullptr) {
        if (tempHead->key == key) {
            std::cout << "Element found ||" << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
            status = true;
            break;
        }

        tempHead = tempHead->nextNode;
    }
    if (!status) {
        std::cout << "Element not found.\n";
    }
    
    return tempHead;
}

void SimpleLinkedList::display() const{
    std::cout << "Simple Linked List size: "<< SimpleLinkedList::size << " --------------------\n";
    Node* tempHead = this->head;

    while (tempHead != nullptr) {
        std::cout << "Element || " << "key: " << tempHead->key << " value: " << tempHead->data << " ptr: " << tempHead << " Next Node: " << tempHead->nextNode << std::endl;
        tempHead = tempHead->nextNode;
    }
    std::cout << "-----------------------------------\n";
}
void SimpleLinkedList::reverse() { 
    Node* prev = nullptr;
    Node* current = this->head;
    Node* next = nullptr;

    while(current != nullptr) {
        next = current->nextNode; // Sonraki düğümü kaydet
        current->nextNode = prev; // Current'ın next işaretçisini önceki düğüme yönlendir

        prev = current; // Önceki düğümü güncelle
        current = next; // Current'ı sonraki düğüme yönlendir   
    }

    this->head = prev;

    this->display();
}

SimpleLinkedList::~SimpleLinkedList(){
    std::cout << "Derived Class: Simple Linked List Destructor Called\n";
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->nextNode;
        delete current; // Düğümü serbest bırak
        current = next; // Bir sonraki düğüme geç
    }

    head = nullptr; // Başlangıç noktasını null yap
    size = 0; // Liste boyutunu sıfırla
}
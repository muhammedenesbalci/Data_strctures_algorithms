#include <iostream>
#include "Array.h"

// Constructor
Array::Array(int size, const int* initial_arr) : size(size), dynamic_array(nullptr){
    std::cout << "Constructor Called\n";
    
    // Dynamic memory Allocation
    this->dynamic_array = new int[size];

    // Transfer normal array to dynamic array
    for (int i = 0; i < size; ++i) {
        this->dynamic_array[i] = initial_arr[i];
    }
}

// Print Array elements
void Array::print_array() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "array" << "[" << i << "]: " << this->dynamic_array[i] << std::endl;
    }
}
// Extend dynmaic array
void Array::extend_array() {
    int new_size = this->size + 1;

    int* temp_arr = new int[new_size];

    // Transfer old dynamic array to new dynamic array
    for (int i = 0; i < size; ++i) {
        temp_arr[i] = this->dynamic_array[i];
    }
    //delete old heap memory
    delete[] this->dynamic_array;
    
    //update new heap memory u shoul not delete temp_arr
    this->dynamic_array = temp_arr;
    this->size = new_size;
    temp_arr = nullptr;

    std::cout << "Array size updated: " << this->size << "\n" <<std::endl;
}

void Array::insert_element(int element, int index) {
    if(index > this->size || index < 0) {
        std::cout << "index error, max size: " << size << std::endl;
        return;
    }
    
    this->extend_array();
    int max_index = size - 1;
    

    // shift elements if it necessary
    for(int i = max_index; i > index; --i) {
        this->dynamic_array[i] = this->dynamic_array[i - 1];
    }

    this->dynamic_array[index] = element;
    std::cout << "array" << "[" << index << "]: " << element << std::endl;
    std::cout << "element added\n\n";
    
}

// narrow array size
void Array::narrow_array() {
    int new_size = size -1;
    int* temp_array = new int[new_size];

    for(int i = 0; i < new_size ; ++i) {
        temp_array[i] = this->dynamic_array[i];
    }

    delete[] dynamic_array;

    this->dynamic_array = temp_array;
    this->size = new_size;

    temp_array = nullptr;
    std::cout << "size reduces, new size: " << this->size << std::endl;
}

// delete element
void Array::delete_element(int index) {
    int max_index = size - 1;
    
    if(index > max_index || index < 0) {
        std::cout << "index error, max size: " << size << std::endl;
        return;
    }

    std::cout << "array" << "[" << index << "]: " << this->dynamic_array[index] << std::endl;
    std::cout << "element deleted\n\n";

    // shift elements if it necessary
    for(int i = index ; i <= max_index; ++i) {
        this->dynamic_array[i] = this->dynamic_array[i + 1];
    }
    this->narrow_array();
}

// search element
int Array::search_element(int element) const {
    for (int i = 0; i < this->size; ++i) {
        if (this->dynamic_array[i] == element) {
            std::cout << "element found at: " << i << std::endl;
            return i;
        } else {
            std::cout << "element not found\n";
        }   
    }

    return -1;
}

// update element
void Array::update_element(int index, int element){
    if(index >= this->size || index < 0) {
        std::cout << "index error, max size: " << size << std::endl;
        return;
    }

    this->dynamic_array[index] = element;
    std::cout << "element updated\n";
}
// Destrcutor
Array::~Array(){
    std::cout << "Destrcutor Called\n";
    delete[] this->dynamic_array;
}
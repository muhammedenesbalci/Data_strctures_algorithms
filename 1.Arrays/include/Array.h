#include <iostream>

class Array {
private:
    int size;
    int *dynamic_array;

    // extend dynmaic array size
    void extend_array();

    // narrow array size
    void narrow_array();

public:
    // Constructor
    Array(int size, const int* initial_arr);

    // Print Array elements
    void print_array() const;

    // insert element
    void insert_element(int element, int index);

    // delete element
    void delete_element(int index);

    // search element
    int search_element(int index) const;

    // update element
    void update_element(int index, int element);

    // Destrcutor
    ~Array();
};


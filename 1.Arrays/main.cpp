#include <iostream>
#include "include/Array.h"

using namespace std;


int main() {
    int size = 3;
    int arr[size] = {10, 20, 30};

    cout << "initial array******************************************\n" << endl;
    Array dynmaic_array(size, arr);
    dynmaic_array.print_array();

    cout << "\nAdding elements****************\n" << endl;

    cout << "\n\nelement added this 0th index --------" << endl;
    dynmaic_array.insert_element(90, 0);
    dynmaic_array.print_array();

    cout << "\n\nelement added this 1th index --------" << endl;
    dynmaic_array.insert_element(91, 1);
    dynmaic_array.print_array();

    cout << "\n\nelement added this 4th index --------" << endl;
    dynmaic_array.insert_element(94, 4);
    dynmaic_array.print_array();

    cout << "\n\nelement added this 5th index --------" << endl;
    dynmaic_array.insert_element(95, 5);
    dynmaic_array.print_array();

    cout << "\n\nelement added this 6th index --------" << endl;
    dynmaic_array.insert_element(96, 6);
    dynmaic_array.print_array();

    cout << "\n\nelement added this 2th index --------" << endl;
    dynmaic_array.insert_element(92, 2);
    dynmaic_array.print_array();


    cout << "\nRemoving elements*****************************************\n" << endl;
    cout << "\n\nelement deleted this 2th index --------" << endl;
    dynmaic_array.delete_element(2);
    dynmaic_array.print_array();

    cout << "\n\nelement deleted this 3th index --------" << endl;
    dynmaic_array.delete_element(3);
    dynmaic_array.print_array();

    cout << "\n\nelement deleted this 4th index --------" << endl;
    dynmaic_array.delete_element(4);
    dynmaic_array.print_array();

    cout << "\n\nelement deleted this 1th index --------" << endl;
    dynmaic_array.delete_element(1);
    dynmaic_array.print_array();

    cout << "\n\nelement deleted this 0th index --------" << endl;
    dynmaic_array.delete_element(0);
    dynmaic_array.print_array();

    cout << "\nSearch elements*****************************************\n" << endl;
    dynmaic_array.print_array();

    int element;

    element = 92;
    cout << "\nlooking for:"<< element <<" --------" << endl;
    dynmaic_array.search_element(element);

    element = 10;
    cout << "\nlooking for:"<< element <<" --------" << endl;
    dynmaic_array.search_element(element);

    element = 96;
    cout << "\nlooking for:"<< element <<" --------" << endl;
    dynmaic_array.search_element(element);

    cout << "\nUpdate elements*****************************************\n" << endl;
    
    dynmaic_array.update_element(0, 10);
    dynmaic_array.update_element(1, 20);
    dynmaic_array.update_element(2, 30);
    dynmaic_array.update_element(3, 40);
    dynmaic_array.update_element(4, 50);
    dynmaic_array.print_array();


    return 0;
}
/**
* Test file for linked_list.cpp
*/

#include <iostream>

#include "linked_list.hpp"

using namespace std;



/**
* Test creating new list
*/
bool test_new_list(){
    LinkedList * p_test = new LinkedList();
    bool ret_val = false;

    if (nullptr != p_test)
    {
        ret_val = true;
        delete p_test;
    }

    return ret_val;
}

/**
* Delete a list
*/
bool test_delete_list(){
    LinkedList * p_test = new LinkedList();
    bool ret_val = false;

    delete p_test;

    if (nullptr == p_test)
    {
        ret_val = true;
    }

    return ret_val;
}

/**
* Does len work?
*/
bool test_len_list(){
    LinkedList * p_list = new LinkedList();
    bool ret_val = true;
    int one = 1;
    int two = 2;
    int three = 3;

    if (0 != p_list->len())
    {
        ret_val = false;
        goto EXIT;
    }

    p_list->insert_front(&one);
    p_list->insert_front(&two);
    p_list->insert_front(&three);

    if (3 != p_list->len())
    {
        ret_val = false;
        goto EXIT;
    }

EXIT:
    return ret_val;
}

/**
* Main function to run tests
*/
int main (int argc, char ** argv){
    cout << "test\n";

    cout << "Test constructor: " << test_new_list() << endl;
    cout << "Test destructor: " << test_delete_list() << endl;
    cout << "Test len: " << test_len_list() << endl;
}

/**
* Test file for linked_list.cpp
*/

#include <iostream>

#include "linked_list.hpp"

using namespace std;



/**
*
*/
bool test_new_list(){
    LinkedList * p_test = new LinkedList();
    bool ret_val = false;

    if (nullptr == p_test)
    {
        cout << "null list\n";
    }
    else
    {
        cout << "good list\n";
    }

    return ret_val;
}

/**
* Main function to run tests
*/
int main (int argc, char ** argv){
    cout << "test\n";

    test_new_list();
}

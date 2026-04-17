//
// Created by nick on 4/17/26.
//

#include <iostream>

#include "linked_list.hpp"

using namespace std;

/**
* Constructor. Creates new LinkedList with null head.
*/
LinkedList::LinkedList()
{
    p_head = nullptr;
}

/**
* Destructor. Destroys linked list and all items within.
*/
LinkedList::~LinkedList()
{
    node_t * p_curr = p_head;

    while (p_curr != nullptr)
    {
        node_t * p_temp = p_curr;
        p_curr = p_curr->next;
        delete p_temp;
    }
}

bool LinkedList::insert_front(void * p_data){

    bool ret_val = false;
    node_t * p_new = nullptr;

    if (nullptr == p_data){
        cerr << "LinkedList::insert_front: Bad argument passed in\n";
        goto EXIT;
    }

    // Try/catch around 'new' call
    try {
        // Create new node with p_data and current p_head as next. Will work if p_head is NULL or valid.
        p_new = new node_t(p_data, p_head);
    } catch (const std::bad_alloc& except) {
        cerr << "LinkedList::insert_front: Out of memory; node init failed\n";
        goto EXIT;
    }

    // Because p_new will have next set to the old head, this always works when adding to front.
    p_head = p_new;
    ret_val = true;

EXIT:
    return ret_val;
}

bool LinkedList::insert_back(void * p_data){
    bool ret_val = false;

    node_t * p_new = nullptr;
    node_t * p_curr = p_head;

    if (nullptr == p_data){
        cerr << "LinkedList::insert_back: Bad argument passed in\n";
        goto EXIT;
    }

    // Try/catch around 'new' call
    try {
        // Create new node with p_data NULL next node.
        p_new = new node_t(p_data, NULL);
    } catch (const std::bad_alloc& except) {
        cerr << "LinkedList::insert_back: Out of memory; node init failed\n";
        goto EXIT;
    }

    // Loop through until last node
    while (nullptr != p_curr->next)
    {
        p_curr = p_curr->next;
    }

    p_curr->next = p_new;
    ret_val = true;

EXIT:
    return ret_val;
}

// Delete functions
/**
*  Remove front of the list, return true if success.
*     remove_front on an empty list will return false.
*/
bool LinkedList::remove_front(){
    bool ret_val = false;
    node_t * p_temp = p_head;

    if (nullptr == p_head){ // Empty list
        goto EXIT;
    }

    p_head = p_temp->next;
    ret_val = true;

    delete p_temp; // Free node

EXIT:
    return ret_val;
}

/**
*   Remove back of list. Return true if success
        remove_back on empty list will return false
*/
bool LinkedList::remove_back(){
    bool ret_val = false;
    node_t * p_temp = p_head;
    node_t * p_prev = nullptr;

    if (nullptr == p_head){ // Empty list
        goto EXIT;
    }

    if (nullptr == p_head->next){ // Single item list
        p_head = nullptr;
        goto SUCCESS;
    }

    while (nullptr != p_temp->next)
    {
        p_prev = p_temp;
        p_temp = p_temp->next;
    }

    p_prev->next = nullptr;

SUCCESS:
    ret_val = true;
    delete p_temp; // Free node

EXIT:
    return ret_val;
}

// Search functions
/**
*  Search for a value. If found, return true. If not, return false.
*/
bool LinkedList::contains_value(void * p_data){
    bool ret_val = false;
    node_t * p_temp = p_head;

    if (nullptr == p_data) // Bad args
    {
        goto EXIT;
    }

    if (nullptr == p_head) { // Empty list
        goto EXIT;
    }

    while (nullptr != p_temp)
    {
        if (p_data == p_temp->data)
        {
            ret_val = true;
            break;
        }
        p_temp = p_temp->next;
    }

EXIT:
    return ret_val;
}


/**
* Find and delete a value
    Returns true only value found AND deleted from list
*/
bool LinkedList::delete_value(void * p_data){
    bool ret_val = false;
    node_t * p_temp = p_head;
    node_t * p_prev = nullptr;

    if (nullptr == p_head){ // Empty list
        goto EXIT;
    }

    if (p_data == p_head->data) // Head of list is bad value
    {
        ret_val = remove_front();
        goto EXIT;
    }

    if (nullptr == p_head->next){ // Single item list
        if (p_data == p_head->data) // found value
        {
            p_head = nullptr;
            ret_val = true;
            delete p_temp;
        }
        goto EXIT;
    }

    // Since we already checked the first value, assign p_prev to avoid null ptr dereference potential below.
    p_prev = p_temp;
    p_temp = p_temp->next;

    while (nullptr != p_temp->next)
    {
        if (p_data == p_temp->data) // Found data!
        {
            p_prev->next = p_temp->next; // link the previous and next nodes
            ret_val = true;
            delete p_temp; // Free node
            break;
        }

        p_prev = p_temp;
        p_temp = p_temp->next;
    }

EXIT:
    return ret_val;
}

// Util

/**
*     Print list
*
*    For now, just print the pointers.
*/
void LinkedList::print_list(){
    cout << "Linked list contains following pointers:\n";

    if (isEmpty()){
        cout << " - None (empty list)\n";
    }
    else{
        node_t * p_temp = p_head;

        while (nullptr != p_temp){
            printf(" - %p\n", p_temp->data);
            p_temp = p_temp->next;
        }
    }
}

/**
*  Check if list is empty. Return true if empty, false if not empty.
*/
bool LinkedList::isEmpty(){

    bool ret_val = false;

    if (nullptr == p_head)
    {
        ret_val = true;
    }

    return ret_val;
}

/**
* Return length of the linked list as size_t.
*/
size_t LinkedList::len(){
    size_t counter = 0;

    // Iterate through items to get count
    node_t * p_temp = p_head;

    while (nullptr != p_temp){
        p_temp = p_temp->next;
        counter++;
    }

    return counter;
}

// End of linked_list.cpp
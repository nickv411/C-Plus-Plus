//
// Created by nick on 4/17/26.
//

#include <iostream>

#include "linked_list.hpp"


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
    node_t * p_new = NULL;

    if (nullptr == p_data){
        std::cerr << "LinkedList::insert_front: Bad argument passed in\n";
        goto EXIT;
    }

    // Try/catch around 'new' call
    try {
        // Create new node with p_data and current p_head as next. Will work if p_head is NULL or valid.
        p_new = new node_t(p_data, p_head);
    } catch (const std::bad_alloc& except) {
        std::cerr << "LinkedList::insert_front: Out of memory; node init failed\n";
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

    return ret_val;
}
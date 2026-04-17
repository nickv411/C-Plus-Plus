//
// Created by nick on 4/17/26.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>


class LinkedList
{
private:

    struct node_t {
        void * data;
        node_t * next;

        node_t(void * p_data, node_t * p_next) : data(p_data), next(p_next) {};
    };

    node_t * p_head;

public:
    // Constructor/Destructor

    /**
    *  LinkedList constructor. Creates class
    */
    LinkedList();

    /**
    *  LinkedList destructor. Cleans up and deletes.
    */
    ~LinkedList();

    // Adding functions
    bool insert_front(void * p_data);
    bool insert_back(void * p_data);

    // Delete functions
    bool remove_front();
    bool remove_back();

    // Search functions
    bool contains_value(void * p_data);
    bool delete_value(void * p_data);

    // Util
    void print_list();
    bool isEmpty();
    size_t len();

};

#endif //LINKED_LIST_H

// End of linked_list.hpp

/**
* @file solution.hpp
* @brief Solution header file for Leetcode "Add Two Numbers" challenge.
* @author Nick Vincent
* @date 07 APR 2026
*/

#ifndef SOLUTION_H
#define SOLUTION_H



struct ListNode {
    int val;
    ListNode* next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#endif //SOLUTION_H

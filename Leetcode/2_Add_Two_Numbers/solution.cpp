/**
* @file solution.cpp
* @brief Solution file for Leetcode "Add Two Numbers" challenge.
* @author Nick Vincent
* @date 07 APR 2026
*/

#include <cstddef>
#include "solution.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * p_curr_l = l1;
        ListNode * p_curr_2 = l2;

        ListNode * p_new_head = new ListNode();

        int carry = 0;
        ListNode * p_curr = p_new_head;

        while ((NULL != p_curr_l) || (NULL != p_curr_2))
        {
            if ((NULL != p_curr_l) && (NULL != p_curr_2))
            {
                int sum = p_curr_l->val + p_curr_2->val;

                int val = (sum + carry) % 10;
                carry = (sum + carry) >= 10;
                p_curr->val = val;
            }
            else if (NULL != p_curr_l)
            {
                int val = (p_curr_l->val + carry) % 10;
                carry = (p_curr_l->val + carry) >= 10;
                p_curr->val = val;
            }
            else if (NULL != p_curr_2)
            {
                int val = (p_curr_2->val + carry) % 10;
                carry = (p_curr_2->val + carry) >= 10;
                p_curr->val = val;
            }
            else
            {
                // End of both. Though shouldn't even actually be able to hit this.
                break;
            }

            if (NULL != p_curr_l) // Update l1 tracker. Prevent NULL dereference.
            {
                p_curr_l = p_curr_l->next;
            }

            if (NULL != p_curr_2) // Update l2 tracker. Prevent NULL dereference.
            {
                p_curr_2 = p_curr_2->next;
            }


            if ((NULL == p_curr_l) && (NULL == p_curr_2))
            {
                if (0 == carry)
                {
                    break;
                }
                else // Catch edge case of carry bit with NULL lists at next index.
                {
                    ListNode * p_tmp = new ListNode(1, NULL);
                    p_curr->next = p_tmp;
                    break;
                }
            }

            // Create follow on node since we still have at least one list to iterate through.
            ListNode * p_tmp = new ListNode();
            p_curr->next = p_tmp;
            p_curr = p_tmp;
        }

        return p_new_head;
    }
};
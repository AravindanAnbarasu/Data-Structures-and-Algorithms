#include <bits/stdc++.h>
using namespace std;

/* Approach: Linked List 
*/

class Solution {
public:

    struct ListNode 
    {
        int val;
        ListNode *next;
    };

    ListNode* deleteDuplicates(ListNode* head)
    {

        // Base case: empty list 
        if (head == nullptr)
            return head;

        // Pointer to traverse the list
        ListNode* temp = head;

        // Traverse until the last node
        while (temp->next != nullptr) 
        {
            // Assume that 1st node is always unique, start checking from 2nd node
            // If temp value equals next value → duplicate found
            if (temp->val == temp->next->val) 
            {
                // Skip the duplicate node
                temp->next = temp->next->next;
            }
            else 
            {
                // Move the temp pointer to next distinct element
                temp = temp->next;
            }
        }

        return head;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given the head of a sorted linked list, delete all duplicates such that each element
    appears only once. Return the linked list sorted as well.

    Example 1:
    Input: head = [1,1,2]
    Output: [1,2]

    Example 2:
    Input: head = [1,1,2,3,3]
    Output: [1,2,3]
*/
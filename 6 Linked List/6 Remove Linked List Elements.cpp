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

    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node and make (dummy.next = head) which helps to operate on head node
        ListNode dummy;
        dummy.val = 0;
        dummy.next = head;

        // Use a pointer to traverse the list
        ListNode* temp = &dummy;

        // Traverse until the end of the list
        while (temp->next != nullptr) 
        {
            // Start from dummy. If the next node's value == val
            if (temp->next->val == val) 
            {
                // Skip the node
                temp->next = temp->next->next;
            } 
            else 
            {
                // Move temp pointer to next node
                temp = temp->next;
            }
        }

        // The new head is dummy.next
        return dummy.next;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Remove a node by value
*/

/* Question:
    Given the head of a linked list and an integer val, remove all the nodes of the linked list
    that has Node.val == val, and return the new head.

    Example 1:
    Input: head = [1,2,6,3,4,5,6], val = 6
    Output: [1,2,3,4,5]

    Example 2:
    Input: head = [], val = 1
    Output: []

    Example 3:
    Input: head = [7,7,7,7], val = 7
    Output: []
*/
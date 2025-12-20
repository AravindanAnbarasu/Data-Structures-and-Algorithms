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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {

        // Dummy node = fake node placed before the real head of the merged list to operate on head node
        ListNode* dummy = new ListNode();
        dummy->val = 0;
        dummy->next = nullptr;

        // Use a pointer to traverse the list
        ListNode* temp = dummy;

        // While both lists have nodes
        while (list1 != nullptr && list2 != nullptr) 
        {

            // Compare values and attach smaller node
            if (list1->val <= list2->val) {
                temp->next = list1;           // attach small list1 node to temp
                list1 = list1->next;          // jump to next element in list1 for comparison
            } else {
                temp->next = list2;           // attach small list2 node to temp
                list2 = list2->next;          // jump to next element in list1 for comparison
            }

            temp = temp->next;    // jump to next element in temp
        }

        // Attach remaining nodes (only one list will be non-empty)
        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;

        // Return merged list (skipping dummy node)
        return dummy->next;
    }
};

/**************************************************************************
 * Time Complexity : O(n + m), where n and m are lengths of the two lists *
 * Space Complexity: O(1)                                                 *
 **************************************************************************/

/* Remarks: 
    
*/

/* Question:
    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by splicing together
    the nodes of the first two lists.

    Return the head of the merged linked list.

    Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Example 2:
    Input: list1 = [], list2 = []
    Output: []

    Example 3:
    Input: list1 = [], list2 = [0]
    Output: [0]
*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: Linked List 
*/

class Solution {
public:

    struct Node {
        int val;
        Node *next;
    };

    Node* reverseList(Node* head) {

        Node* curr = head;
        Node* prev = nullptr;

        // Traverse the linked list
        while (curr != nullptr) { // Note: not (curr-> next != nullptr), it will skip checking last node

            Node* temp = curr->next; // save the link address before breaking
            curr->next = prev;           // create a new reverse link

            prev = curr;                 // move the prev pointer to current
            curr = temp;                 // move the curr pointer to next element
        }

        // At the end, prev will be the new head of the reversed list
        return prev;

        /* NOTE: If they ask to implement in Recursion mention, recursion cause overhead with 
        Space Complexity O(n), where as this iterative method its O(1) */
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
*/
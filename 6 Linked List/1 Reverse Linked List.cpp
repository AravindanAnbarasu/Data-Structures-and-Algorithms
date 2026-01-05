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

        Node* temp = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;

        //Idea! = Reverse the pointer arrows in the Linked List. Job Done!
        // Original :            1 -> 2 -> 3 -> 4-> nullptr
        // Reversed : nullptr <- 1 <- 2 <- 3 <- 4 

        // Traverse the linked list, always use "temp" for traversal
        while (temp != nullptr) // Note: not (temp->next != nullptr), then it will skip checking last node
        { 
            nextNode = temp->next;       // save the link address before breaking
            temp->next = prev;           // create a new reverse link

            prev = temp;                 // move the prev pointer to temp node
            temp = nextNode;             // move the temp pointer to next node
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
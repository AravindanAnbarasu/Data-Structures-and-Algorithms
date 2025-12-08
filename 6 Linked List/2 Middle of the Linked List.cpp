#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers (Slow and Fast Pointers) 
*/

class Solution {
public:

    struct Node {
        int val;
        Node *next;
    };

    Node* middleNode(Node* head) {

        Node* slow = head; // Slow pointer moves 1 step at a time
        Node* fast = head; // Fast pointer moves 2 steps at a time

        /* When fast reaches the end, slow will be at the middle.
           Automatically handles both:
           Odd length → slow stops at exact middle
           Even length → slow stops at the 2nd middle (as LeetCode requires) */

        /* Traverse the list until fast reaches the end
           We check both fast != nullptr && fast->next != nullptr 
           because fast jumps two steps each iteration */

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;          // move slow by 1
            fast = fast->next->next;    // move fast by 2
        }

        // When fast reaches the end, slow will be at the middle
        return slow;
    }
};

/***************************************************************************
 * Time Complexity : O(n),=> Even though fast moves twice as quickly,      *
                     the number of iterations is still proportional to n/2 *  
                     and 1/2 is a constant.                                *
                     NOTE: not O(log n) as in binary search, there every   * 
                     time search space reduces by n/2, here only once      *

 * Space Complexity: O(1)                                                  *
 ***************************************************************************/

/* Remarks: 
    
*/

/* Question:
    Given the head of a singly linked list, return the middle node of the linked list.

    If there are two middle nodes, return the second middle node.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [3,4,5]
    Explanation: The middle node of the list is node 3.

    Example 2:
    Input: head = [1,2,3,4,5,6]
    Output: [4,5,6]
    Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/
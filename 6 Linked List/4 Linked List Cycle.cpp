#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers (i and j Pointers)/(Sliding Window), as i and j(window)
slides in every loop.
*/

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
    };

    bool hasCycle(ListNode *head) {

        // Base case: empty list or single node cannot form a cycle
        if (head == NULL || head->next == NULL)
            return false;

        // Two pointers: i slow pointer moves 1 step, j fast pointer moves 2 steps
        ListNode* i = head;
        ListNode* j = head;

        // Traverse the list, check j != NULL aswell because sometimes since fast pointer is moving
        // 2 steps, it may jump to a one node after last node i.e, NULL node when no cycle
        while (j != NULL && j->next != NULL) {

            i = i->next;          // move by +1
            j = j->next->next;    // move by +2

            // If both pointers meet, cycle exists
            if (i == j)
                return true;
        }

        // If j->next reaches NULL, no cycle
        return false;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    A Cycle always exits from the tail node to any other node. But always from tail node, not in
    between.

    1 → 2 → 3 → 4 → 5
                ↑   ↓
                ← ← ←

    1 → 2 → 3 → 4 → 5
    ↑               ↓
    ← ← ← ← ← ← ← ← ←
*/

/* Question:
    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again 
    by continuously following the next pointer. Internally, pos is used to denote the index of the node
    that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    Example 1:
        3 → 2 → 0 → -4
            ↑        ↓
            ← ← ← ← ←
    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    Example 2:
        1 → 2
        ↑   ↓
        ← ← ←
    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

    Example 3:
        1-> null
    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.
*/
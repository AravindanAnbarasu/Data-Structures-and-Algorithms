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

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

       // Hash set to store "addresses of nodes" in list A
      unordered_set<ListNode*> hash;

      // Traverse list A and store "addresses of nodes"
      ListNode* tempA = headA;
      while (tempA != NULL) 
      {
          hash.insert(tempA);   // store node address
          tempA = tempA->next;
      }

      // Traverse list B and check for intersection
      ListNode* tempB = headB;
      while (tempB != NULL)
      {
          // If node address is already seen, intersection found
          if (hash.find(tempB) != hash.end()) 
          {
              return tempB;
          }

          tempB = tempB->next;
      }

      // No intersection found
      return NULL;
  }

};

/**************************************************************************
 * Time Complexity : O(m + n), where n and m are lengths of the two lists *
 * Space Complexity: O(m)                                                 *
 **************************************************************************/

/* Remarks:
    If we have two pointers and move them normally, they won’t align at the same time if one list is longer.
    Example: 
    List A: a1 → a2 → a3 → c1 → c2
    List B: b1 → b2 → b3 → b4 → c1 → c2

    So go for Hashing technique to store "addresses of nodes"

*/

/* Question:
    Given the heads of two singly linked-lists headA and headB, return the node at which
    the two lists intersect. If the two linked lists have no intersection at all, return null.

    List A: 1 → 2 → 3 -> 4
                          ↘
                            7 → 8
                          ↗
    List B:          5 → 6 

*/
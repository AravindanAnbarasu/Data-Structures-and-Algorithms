#include <bits/stdc++.h>
using namespace std;

/* Approach: Vector + Two Pointer 
*/

class Solution {
public:

    struct ListNode
    {
        int val;
        ListNode *next;
    };

    bool isPalindrome(ListNode* head) {

        vector<int> values;

        // Store all linked list values into a vector
        while (head != NULL) 
        {
            values.push_back(head->val);
            head = head->next;
        }

        // Check palindrome using two pointers
        int left = 0;
        int right = values.size() - 1;

        while (left < right) 
        {
            if (values[left] != values[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true; // All values matched
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    An integer is a palindrome when it reads the same forward and backward
    For example, 121 is a palindrome while 123 is not
*/

/* Question:
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

    Example 1:
    Input: head = [1,2,2,1]
    Output: true

    Example 2:
    Input: head = [1,2]
    Output: false
*/
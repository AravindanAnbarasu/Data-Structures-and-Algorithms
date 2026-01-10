#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers -> left(0) and right(size-1)
*/

class Solution {
public:

    void reverseString(string &s) {

        int left = 0;
        int right = s.size() - 1;   // s.length() - 1 , because the index starts from 0

        // Swap characters manually untill left == right, i.e -> left < right
        while (left < right) 
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;   // Increment the left pointer
            right--;  // Devrement the right pointer
        }
    }
};

// When the input is Character Array rather than String, same solution
void reverseString(vector<char>& s) 

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    1. When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0

    2. C++ strings are not terminated by '\0' character at end 
*/

/* Question:
    Write a function that reverses a string. The input string is given as an array of characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:
    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
*/
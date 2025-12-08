#include <bits/stdc++.h>
using namespace std;

/* Approach: Single Right Pointer 
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int length = 0;
       
        int i = s.length() - 1; //  start from the end of the string(last index) 

        // Step 1: Skip trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters until next space
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;  // This is the length of the last word
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    1. When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0
*/

/* Question:
    Given a string s consisting of words and spaces, return the length of the last word in the string.

    A word is a maximal substring consisting of non-space characters only.

    Example 2:
    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.
*/
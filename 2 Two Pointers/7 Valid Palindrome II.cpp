#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers (Left and Right Pointers)
*/
class Solution {
public:

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                /*----------------Additional checks from usual palindrome logic----------------*/

                // Before returning false, try deleting at most 1 character and check if it can become palindrome
                // Option 1: skip left char
                bool skipLeft = isPalindrome(s, left + 1, right);
                // Option 2: skip right char
                bool skipRight = isPalindrome(s, left, right - 1);

                return skipLeft || skipRight;

                /*----------------Additional checks from usual palindrome logic----------------*/
            }

            left++;
            right--;
        }

        return true;
    }

    // function to check if a string is palindrome or not
    bool isPalindrome(string s, int left, int right) {

        while (left < right)
        {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.

    Example 1:
    Input: s = "aba"
    Output: true

    Example 2:
    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.

    Example 3:
    Input: s = "abc"
    Output: false
*/
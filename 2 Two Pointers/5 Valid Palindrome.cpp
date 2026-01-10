#include <bits/stdc++.h>
using namespace std;

/* Optimal Approach: Two Pointers -> left(0) and right(size-1)
*/

class Solution {
public:
    bool isPalindrome(const std::string& s) 
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            /*----------------Additional checks from usual palindrome logic----------------*/

            // Move left pointer until next alphanumeric character is found
            while (left < right && !isalnum(s[left]))
                left++;

            // Move right pointer until next alphanumeric character is found
            while (left < right && !isalnum(s[right]))
                right--;

            /*----------------Additional checks from usual palindrome logic----------------*/

            if (tolower(s[left]) != tolower(s[right]))  // toupper() -> to convert to upper case
            {
                return false;
            }

            // If match found, continue to check other characters in the string
            left++;
            right--;
        }

        return true; // all matched
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    - An string is a palindrome when it reads the same forward and backward. Eg: radar

    - You can also use reverse(str.begin(), str.end()); reverses the original string str. 
      Time: O(n) Space: O(1) 
*/

/* Question:
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and
    removing all non-alphanumeric characters, it reads the same forward and backward. 
    Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

    Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.
*/
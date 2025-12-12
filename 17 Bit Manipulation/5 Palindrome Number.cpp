#include <bits/stdc++.h>
using namespace std;

/* Approach: Reverse String in-built function
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool isPalindrome(int x) {

        string s = to_string(x);
        string rev = s;

        // Time Complexity: O(n) and Space Complexity: O(n)
        reverse(rev.begin(), rev.end());

        return s == rev;
    }
};

/* Optimal Approach: Bit Manipulation
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are NOT palindrome (because of '-' sign)
        if (x < 0) {
            return false;
        }

        // We use long long because reversing an integer can easily overflow a normal int
        // If x = 2147483647 (largest 32-bit int) Reversing it gives: 7463847412

        long long rev = 0;  // will store the reversed number
        long long num = x;  // copy original number so we don't modify x
        int lastDigit = 0;  // lastDigit of num

        // Reverse the number completely
        while (num != 0) {
            lastDigit = num % 10;            // extract last digit of num
            rev = rev * 10 + lastDigit;      // build reversed number
            num = num / 10;                  // remove last digit from num
        }

        // If reversed number equals original number → it is a palindrome
        return rev == x;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks:
    An integer is a palindrome when it reads the same forward and backward
    For example, 121 is a palindrome while 123 is not
    
*/

/* Question:
    Given an integer x, return true if x is a palindrome, and false otherwise

    An integer is a palindrome when it reads the same forward and backward
    For example, 121 is a palindrome while 123 is not

    Example 1:
    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left

    Example 2:
    Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121- 
    Therefore it is not a palindrome
*/
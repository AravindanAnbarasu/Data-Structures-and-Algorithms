#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Left Pointers on different containers
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {

        // i -> pointer for s, j -> pointer for t
        int i = 0, j = 0;

        while (j < t.size() && i < s.size()) {

            // If characters match, move pointer i
            if (s[i] == t[j]) {
                i++;
            }

            // Always move pointer j in t
            j++;
        }

        // If i reached the end of s,
        // it means ALL characters of s matched in order
        return i == s.size();
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 

*/

/* Question:
    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string
    by deleting some (can be none) of the characters without disturbing the relative
    positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde"
    while "aec" is not).

    Example 1:
    Input: s = "abc", t = "ahbgdc"
    Output: true

    Example 2:
    Input: s = "axc", t = "ahbgdc"
    Output: false
*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map 
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Base_case: If lengths differ, not possible to be anagrams
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> hash;

        for (char c : s) {
            hash[c] = hash[c] + 1;  // increment count for each char found in s
        }
   
        for (char c : t) {
            hash[c] = hash[c] - 1;  // decrement for each char found in t
        }

        // Check if any character count is not zero → not an anagram
        for (auto element : hash) {
            if (element.second != 0)
                return false;
        }

        return true; // All counts zero → valid anagram
    }
};

/***************************************************************************
 * Time Complexity : O(n + m), where n and m are lengths of string s and t *                                              *
 * Space Complexity: O(1), since we have max 26 different characters   *
 ***************************************************************************/

/* Remarks: 

    1. An anagram is a string that contains the exact same characters with 
    same count as another string, but the order of the characters can be different 
    
    2. hash[c] : You can just insert a key without a value, but the default value 
    of the datatype will be stored. In our case 0, since int
    
    3. Works for entire ASCII Range of 256 characters, because signed char stores 1 byte , and we dont care signed
    or unsigned char ,because here we use hash and not array for which we subtract with -'a' to get a +ve index
    Follow-Up Q: How to adapt for UNICODE characters. For UNICODE use -> unordered_map<char32_t, int> 
    
*/

/* Question: 

    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:
    Input: s = "rat", t = "car"
    Output: false
*/
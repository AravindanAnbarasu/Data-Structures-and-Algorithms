#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map with frequency count
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Base_case: If lengths differ, not possible to be anagrams
        if (s.length() != t.length()) // In c++, string.size() is same as string.length() 
            return false;

        unordered_map<unsigned char, int> hash;

        for (unsigned char c : s) {
            hash[c] = hash[c] + 1;  // increment count for each char found in s
        }
   
        for (unsigned char c : t) {
            hash[c] = hash[c] - 1;  // decrement for each char found in t
        }

        // Loop the hash, here element is a pair<char,int>
        for (auto element : hash) {
            if (element.second != 0)
                return false;
        }

        return true; // All counts zero → valid anagram
    }
};

/***************************************************************************
 * Time Complexity : O(n)                                                  *
 * Space Complexity: O(1), since we have max 26 different characters       *
 ***************************************************************************/

/* Remarks: 

    1. An anagram is a string that contains the exact (same characters with same count)
    as another string, but the (order of the characters can be different) 
    
    2. hash[c] + 1 : You can just insert a key without a value, but the default value 
    of the datatype will be stored. In our case 0, since int. This is only applicable for hash
    and not "Vector" where  you have to initialize before accessing.
    
    3. Works for entire ASCII Range of 256 characters, because unsigned char stores 0-255 values, 
    but for array we have subtract with -'a' to get a +ve index.
    Follow-Up Q: How to adapt for UNICODE characters. For UNICODE use -> unordered_map<char32_t, int> 

    4. In c++, string.size() is same as string.length() 
    
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
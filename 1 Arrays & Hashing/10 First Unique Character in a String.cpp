#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map with frequency count
*/

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> hash;

        // Count frequency of each character in the string and store it in hash
        for (char c : s) {
            hash[c]= hash[c] + 1;   // increase the count of character 'c' by 1
        }

        // Loop has and find the first character that appears only once
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 1) {            // check if this character occurs exactly once
                return i;                     // return its index
            }
        }

        return -1;                            // no unique character found
    }
};

/************************************************************************
 * Time Complexity : O(n)                                               *
 * Space Complexity: O(1), since we have at most 26 different Alphabets *
 ************************************************************************/

/* Remarks: 
    1. hash[c] : You can just insert a key without a value, but the default value 
    of the datatype will be stored. In our case 0, since int

    2. Each Find, Insert and Delete in the Hash table costs only O(1) time
*/

/* Question:
    Given a string s, find the first non-repeating character in it and return its index. 
    If it does not exist, return -1.

    Example 1:
    Input: s = "leetcode"
    Output: 0
    Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

    Example 2:
    Input: s = "loveleetcode"
    Output: 2

    Example 3:
    Input: s = "aabb"
    Output: -1
*/
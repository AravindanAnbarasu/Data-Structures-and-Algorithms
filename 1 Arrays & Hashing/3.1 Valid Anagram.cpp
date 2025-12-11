#include <bits/stdc++.h>
using namespace std;

/* Approach: Frequency Count Vector
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Base_case: If lengths differ, not possible to be anagrams
        if (s.length() != t.length())
            return false;

        // Here we assume only lowercase 'a' to 'z' as inputs, so size = 26 and Intialize all to Zero
        // a -> Index[0], b -> Index[1], .....
        vector<int> freqCountVec(26, 0);

        // (char - 'a'), gives the index of lowercase alphabets
        for (char c : s) // increase count for s
        {
            freqCountVec[c-'a'] = freqCountVec[c-'a'] + 1;  
        }

        for (char c : t) // decrease count for t
        {
            freqCountVec[c-'a'] = freqCountVec[c-'a'] - 1;  
        }

        // Check if all zero — means equal counts
        for (int count : freqCountVec) {
            if (count != 0) 
                return false;
        }

        return true; // All good — valid anagram
    }
};

/***************************************************************************
 * Time Complexity : O(n + m), where n and m are lengths of string s and m *                                              *
 * Space Complexity: O(1), since we have max 26 different characters   *
 ***************************************************************************/

/* Remarks: 

    1. An anagram is a string that contains the exact same characters with 
    same count as another string, but the order of the characters can be different 

    2. VECTOR Thumb Rule: whenever you declare a VECTOR, always initialize with (size, default value)
    or (size) like an array, when you access vec[] first even before push_back. 
    As size of vector<int> vec; -> is Zero.

    3. For supporting only Upper Case, only change => subtract by 'A'

    4. For supporting both Upper & Lower Case, 
        --------------------------------------------------------------------------
        vector<int> freqCountVec(52, 0); // 52 slots: [0-25] for A-Z, [26-51] for a-z

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') 
                freqCountVec[c - 'A']++;
            else if (c >= 'a' && c <= 'z') 
                freqCountVec[26 + (c - 'a')]++;   // add +26 for lower case
        }

        for (char c : t) {
            if (c >= 'A' && c <= 'Z') 
                freqCountVec[c - 'A']--;
            else if (c >= 'a' && c <= 'z') 
                freqCountVec[26 + (c - 'a')]--;   // add +26 for lower case
        -------------------------------------------------------------------
        }
    
    5. For supporting entire ASCII Range of 256 characters, (lower case, upper case, special characters)
    
        Example: 'NULL' -> Index[0] ; 'A' -> Index[65] ; 'a' -> Index[97]
        -------------------------------------------------
        vector<int> freqVec(256, 0); // use 256 for entire ASCII range
        for (unsigned char c : s)    // use 'unsigned char'
        {
            freqCountVec[c-'a'] = freqCountVec[c-'a'] + 1;  
        }

        for (unsigned char c : t)   // use 'unsigned char'
        {
            freqCountVec[c-'a'] = freqCountVec[c-'a'] - 1;  
        }
        ------------------------------------------------------
*/

/* Question: 

*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: Frequency Count Vector
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Hash map: Key - charCount string, Value - anagram vector
        unordered_map<string, vector<string>> hash;

        // For each string create a charCount string Key and store it in hash
        for (string s : strs) {

            // Here we assume only lowercase 'a' to 'z' as inputs, so size = 26 and Intialize all to Zero
            // a -> Index[0], b -> Index[1], .....
            vector<int> charCountVec(26, 0);

            // count the characters in each string
            for (char c : s) 
            {
                // (char - 'a'), gives the index of lowercase alphabets
                charCountVec[c-'a'] = charCountVec[c-'a'] + 1;  
            }

            // Build charCount string Key using charCountVec. Eg: key output for: "abb" is "1#2#0#0#.."
            // Using "#" prevents merging ("11" and "1|1" confusion)
            string key = "";
            for (int count : charCountVec)
                key = key + to_string(count) + "#";
            
            // Store it in hash
            hash[key].push_back(s); // since the second in hash is vector we use push_back
        }

        // Move results from hash map into output 2-D vector 
        // (just think as, its a vector where each element inside is again a vector of string, thats it )
        vector<vector<string>> TwoDVec;

        for (auto &entry : hash)
            TwoDVec.push_back(entry.second);

        return TwoDVec;
    }
};

/********************************************************************************************
 * Time Complexity : O(n * m), where n is number if strings and m lengths of longest string *                                              *
 * Space Complexity: O(n), for 2-D Vector                                                    *
 ***************************************************************************/

/* Remarks: 

    1. An anagram is a string that contains the exact (same characters with same count)
    as another string, but the (order of the characters can be different) 

    2. VECTOR Thumb Rule: whenever you declare a VECTOR, always initialize with (size, default value)
    or (size) like an array, when you access vec[] first even before push_back. 
    As size of vector<int> vec; -> is Zero.
    
    3. For supporting all ASCII range, only upper, upper + lower, refer Valid Anagram problem
*/

/* Question: 
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]

*/
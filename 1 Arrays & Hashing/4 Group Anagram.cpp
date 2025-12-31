#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash map + Frequency Count Vector
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Hash map: Key - custom count-string, Value - anagram vector
        unordered_map<string, vector<string>> hash;

        // Step_1: For each string create a custom count-string and store it in hash
        for (string s : strs) {

            // Here we assume only lowercase 'a' to 'z' as inputs, so size = 26 and Intialize all to Zero
            // a -> Index[0], b -> Index[1], .....
            vector<int> freqCountVec(26, 0);

            // count the characters in each string
            for (char c : s) 
            {
                // (char - 'a'), gives the index of lowercase alphabets
                freqCountVec[c-'a'] = freqCountVec[c-'a'] + 1;  
            }

            // Build custom count-string Key using freqCountVec. Eg: key output for: "abb" is "1#2#0#0#.."
            // Using "#" prevents merging ("11" and "1|1" confusion)
            string key = "";
            for (int count : freqCountVec)
                key = key + to_string(count) + "#";
            
            // Store it in hash
            auto it = hash.find(key);

            if (it == hash.end()) // if key not found, insert (NOTE: insert function will skip duplicate keys)
            {
                vector<string> temp;
                temp.push_back(s);

                hash.insert({key,temp}); // { } use pair
            }
            else
            {
                it->second.push_back(s); // since the second in hash is vector we use push_back
            }
        }

        // Step_2: Extract results from hash map into output 2-D vector 
        // (just think as, its a vector where each element inside is again a vector of string, thats it )
        vector<vector<string>> TwoDVec;

        for (auto pair : hash)
            TwoDVec.push_back(pair.second);

        return TwoDVec;
    }
};

/******************************************
 * Time Complexity : O(n)                 *
 * Space Complexity: O(n), for 2-D Vector *                                                    *
 ******************************************/

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
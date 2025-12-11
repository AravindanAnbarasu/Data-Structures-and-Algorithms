#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map 
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        // Hash map to store frequency of each number
        unordered_map<int, int> hash;

        vector<int> result;

        // Count frequency of each element
        for (int num : nums)
        {
            hash[num] = hash[num] + 1; 
        }

        // Check which numbers appear more than n/3 times and add to result
        for (auto pair : hash)
        {
            if (pair.second > nums.size() / 3)   
            {
                result.push_back(pair.first);    
            }
        }

        return result;   // Return all majority elements
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    1. Each Find, Insert and Delete in the Hash table costs only O(1) time

    2. hash[c] : You can just insert a key without a value, but the default value 
    of the datatype will be stored. In our case 0, since int
*/

/* Question:
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:
    Input: nums = [3,2,3]
    Output: [3]

    Example 2:
    Input: nums = [1]
    Output: [1]

    Example 3:
    Input: nums = [1,2]
    Output: [1,2]
*/
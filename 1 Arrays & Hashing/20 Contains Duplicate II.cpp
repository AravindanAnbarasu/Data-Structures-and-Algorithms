#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map 
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        // key   -> number
        // value -> last index where the number appeared
        unordered_map<int, int> hash;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If the number has appeared before, then nums[i] == nums[j] is satisfied
            if (hash.find(nums[i]) != hash.end())
            {
                // Check the index distance condition
                if (abs(i - hash[nums[i]]) <= k)
                    return true;
            }

            // Update the last seen index of the number in hash
            hash[nums[i]] = i;
        }

        // No valid duplicate found
        return false;
    }
};
/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
   Each Find, Insert and Delete in the Hash table costs only O(1) time
*/

/* Question:
    Given an integer array nums and an integer k, return true if there are two distinct indices
    i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true

    Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true

    Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
*/
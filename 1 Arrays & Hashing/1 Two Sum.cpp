#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map with index
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hash;

        for(int i = 0; i< nums.size() ; i++)
        {
            int answer = target - nums[i];

            if(hash.find(answer) != hash.end()) // if found the element in hash table
            {
                return {hash[answer],i}; 
            }

            hash[nums[i]] = i; // if not found, store element in the hash table for future lookups
        }

        return{} ; // Return an empty vector if no solution is found
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
    Given an array of integers nums and an integer target, return indices of the two numbers such 
    that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same 
    element twice.

    You can return the answer in any order.

    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hash;

        for(int i = 0; i< nums.size() ; i++)
        {
            int answer = target - nums[i];

            if(hash.find(answer) != hash.end()) // found the element in hash table ?
            {
                return {hash[answer],i}; 
            }

            hash[nums[i]] = i; // if not found, store element in the hash table for future lookups
        }

        return{}; // Return an empty vector if no solution is found
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

 /* Remarks: Each lookup in the Hash table costs only O(1) time */

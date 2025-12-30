#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Set
   Hash Set -> stores only single element not pair, and that too only unique elements
*/

class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> hash;

        for (int num : nums) {
            
            // If item found in hash set, it exists twice
            if (hash.find(num) != hash.end()) 
            {
                return true;
            }

            // Else insert to hash set for future look-up
            hash.insert(num);
        }

        // No duplicate found 
        return false;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
   - Each Find, Insert and Delete in the Hash table costs only O(1) time
   - hash set only has insert function to add elements, it cannot use [ ] to add or access elements
*/

/* Question:
    Given an integer array nums, return true if any value appears at least twice in the array, 
    and return false if every element is distinct.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: true
    Explanation: The element 1 occurs at the indices 0 and 3.

    Example 2:
    Input: nums = [1,2,3,4]
    Output: false
    Explanation: All elements are distinct
*/
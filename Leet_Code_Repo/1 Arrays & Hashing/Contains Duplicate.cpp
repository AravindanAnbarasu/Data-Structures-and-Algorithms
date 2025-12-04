#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) {

        // Hash Set stores unique values only
        unordered_set<int> hash;

        for (int num : nums) {
            
            // If item found in hash set, it exists twice
            if (hash.find(num) != hash.end()) {
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

 /* Remarks: Each lookup in the Hash table costs only O(1) time */
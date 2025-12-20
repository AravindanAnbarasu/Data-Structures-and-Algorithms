#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash set
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Hash set to store unique elements from nums1
        unordered_set<int> hash;

        // Insert elements of nums1 into the set
        for (int num : nums1)
        {
            hash.insert(num);   // insert() ensures uniqueness automatically
        }

        vector<int> result;

        // Traverse nums2
        for (int num : nums2)
        {
            // If num exists in hash, it's part of intersection
            if (hash.find(num) != hash.end())
            {
                result.push_back(num);     // add to result
                hash.erase(num);        // remove to avoid duplicates
            }
        }

        return result;
    }
};

/***************************************************
 * Time Complexity : O(m + n)                          *
 * Space Complexity: O(m)                          *
 ***************************************************/

/* Remarks: 
    Each Find, Insert and Delete in the Hash table costs only O(1) time
*/

/* Question:
    Given two integer arrays nums1 and nums2, return an array of their intersection. 
    Each element in the result must be unique and you may return the result in any order.

    Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

    Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]
    Explanation: [4,9] is also accepted.
*/
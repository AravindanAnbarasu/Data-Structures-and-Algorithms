#include <bits/stdc++.h>
using namespace std;

/* Approach: Hash Map with frequency count
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> hash;
        int answer = 0;
        int maxCount = 0;

        // Loop the vector and and store the count in hash
        for (int num : nums) 
        {
            hash[num] = hash[num] + 1;
        } 

        // Loop the hash and update the answer
        for (auto element : hash )  // element is a pair<int,int>
        {
            if (element.second > maxCount)
            {
                maxCount = element.second ;   // update the maxCount
                answer = element.first;       // update the answer that has maxCount
            }
        }

        return answer;
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
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.

    Example 1:
    Input: nums = [3,2,3]
    Output: 3

    Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/
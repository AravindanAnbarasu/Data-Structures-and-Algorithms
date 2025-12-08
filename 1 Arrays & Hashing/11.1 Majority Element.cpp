#include <bits/stdc++.h>
using namespace std;

/* Approach: Boyer–Moore Voting Algorithm
*/

/*
    Boyer–Moore Voting Algorithm - MugUp

    - Maintain a leading_candidate and a confidence.
    - Iterate through Array,If confidence = 0, choose a new leading_candidate
    - Increase the confidence if current candiddate is the leading_candidate
    - Else decrease the confidence 
    - Finally the leading_candidate will win
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int leading_candidate = 0;
        int confidence = 0;

        for (auto candidate : nums) {

            if (confidence == 0) 
            {
                leading_candidate = candidate;   // choose a new leading_candidate 
            }

            if (candidate == leading_candidate) { 
                confidence ++;
            } 
            else {
                confidence --;
            }
        }

        return leading_candidate;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 

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
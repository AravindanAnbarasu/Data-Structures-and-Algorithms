#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        // Ex: when k= 5 and array_size = 5, "Rotating 5 times" is same as "Not Rotating"
        // Ex: when k= 6 and array_size = 5, "Rotating 6 times" is same as "Rotating 1 time"
        // So when "rotating times" >= to array size, to optimize rotating efforts, use below
        k = k % nums.size();

        // Reverse the entire array
        my_reverse(nums, 0, nums.size() - 1);

        // Reverse first k elements
        my_reverse(nums, 0, k - 1);  // k-1 since index starts from 0

        // Reverse remaining elements
        my_reverse(nums, k, nums.size() - 1);
    }

    void my_reverse(vector<int>& nums, int l, int r) 
    {
        while (l < r) 
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};
/***************************************************
 * Time Complexity : O(n)                        *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Rotating an array by k is equivalent to moving the last k elements to the front. We can achieve this with three reversals. 
    1. First, reverse the entire array. Now the last k elements are at the front, but in reverse order.
    2. Reverse the first k elements to fix their order.
    3. Finally, reverse the remaining elements to restore their original order.

*/

/* Question:
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Example 1:
    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:
    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
*/
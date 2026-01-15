#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers -> left(0) and right(size-1)
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 2-D vector to store results
        vector<vector<int>> result;

        // Sort the array, so decision to increment left or decrement right pointer can be made based on sum
        // Time Complexity: O(nums.size() log nums.size()) , Space Complexity: O(1)
        sort(nums.begin(), nums.end());

        // Loop the Array and fix one element nums[i]
        for (int i = 0; i < nums.size(); i++)
        {
            // If current number is same as previous, skip to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            /*************** Extra code w.r.t 3Sum ********************/
            // Loop the Array from i+1 and fix second element nums[j]
            for (int j = i + 1; j < nums.size(); j++)
            {
                // If current number is same as previous, skip to avoid duplicate quadruplets
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

            /*************** Extra code w.r.t 3Sum ********************/

                int left = j + 1; // Left pointer start after j -> (j + 1)
                int right = nums.size() - 1;

                // For each nums[i] and nums[j] find remaining two numbers
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) // Found a valid quadruplet!
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Move left pointer forward skipping duplicates
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        // Move right pointer backward skipping duplicates
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        // Move to next set of left and right pointer pair
                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        // Need a bigger sum: move left pointer forward
                        left++;
                    }
                    else
                    {
                        // Need a smaller sum: move right pointer backward
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

/***************************************************
 * Time Complexity : O(n^3)                        *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0

*/

/* Question:
    Given an array nums of n integers, return an array of all the unique quadruplets
    [nums[a], nums[b], nums[c], nums[d]] such that:

    -> 0 <= a, b, c, d < n
    -> a, b, c, and d are distinct.
    -> nums[a] + nums[b] + nums[c] + nums[d] == target
    
    You may return the answer in any order.

    Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
*/
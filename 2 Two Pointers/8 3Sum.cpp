#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers -> left(0) and right(size-1)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        // 2-D vector to store results
        vector<vector<int>> result;

        // Sort the array, so decision to increment left or decrement right pointer can be made based on sum
        // Time Complexity: O(n log n) , Space Complexity: O(1)
        sort(nums.begin(), nums.end());

        // Loop the Array and fix one element nums[i]
        for (int i = 0; i < nums.size(); i++)
        {

            // If current number is same as previous, skip to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;            // Left pointer start -> (i + 1)
            int right = nums.size() - 1; // Right pointer

            // For each nums[i] find remaining two numbers
            while (left < right)
            {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) // Found a triplet!
                {
                    result.push_back({nums[i], nums[left], nums[right]});

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
                else if (sum < 0)
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

        return result;
    }
};

/***************************************************
 * Time Complexity : O(n^2)                        *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0

*/

/* Question:
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
    i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.

    Example 2:
    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.

    Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.
*/
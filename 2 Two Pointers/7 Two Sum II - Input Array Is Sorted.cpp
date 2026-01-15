#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers -> left(0) and right(size-1)
   NOTE: Array is sorted
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            // Found the target sum
            if (sum == target)
            {
                // Return indices +1 as required by the problem statement (1-Indexed)
                return {left + 1, right + 1};
            }
            // Need a bigger sum, move left pointer forward
            else if (sum < target)
            {
                left++;
            }
            // Need a smaller sum, move right pointer backward
            else
            {
                right--;
            }
        }

        return {};
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0

*/

/* Question:
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
    find two numbers such that they add up to a specific target number. Let these two numbers be
    numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, added by one as an integer array
    [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. You may not use the same element twice.
    Your solution must use only constant extra space.

    Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

    Example 2:
    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

    Example 3:
    Input: numbers = [-1,0], target = -1
    Output: [1,2]
    Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/
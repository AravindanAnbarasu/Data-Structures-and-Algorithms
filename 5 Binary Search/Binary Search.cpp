#include <bits/stdc++.h>
using namespace std;

/* Approach: Binary Search (Repeatedly divide the search space into half)
   Note: Works only when the Array is Sorted
*/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // Note: Works only when the Array is Sorted

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            // Note: mid = (left + right)/2 can cause overflow issues. Worst case: (left + right) = 3,100,000,000
            // But INT_MAX = 2,147,483,647. So 3,100,000,000 doesn't fit in a 32-bit signed int.
            int mid = left + (right - left) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Target is in the right, so move the left index to mid + 1
            else if (nums[mid] < target)
                left = mid + 1;

            // Target is in the left half, so move the right index to mid - 1
            else
                right = mid - 1;
        }

        // Target not found
        return -1;
    }
};


/***************************************************
 * Time Complexity : O(log n)                      *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Note: Works only when the Array is Sorted
*/

/* Question:
    Given an array of integers nums which is sorted in ascending order, and an integer target,
    write a function to search target in nums. If target exists, then return its index. Otherwise,
    return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

    Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
*/
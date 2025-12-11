#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers (Slow and Fast Pointers)/(Sliding Window), as i and j(window)
slides in every loop.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // Base_Case: If array is empty, no elements to process
        if (nums.empty())
            return 0;  

        // 'i' is the slow pointer → points to the index of unique element
        int i = 0;

        // 'j' is the fast pointer → scans through the array
        int j = 1;

        // 1st element is always unique as its a sorted aray
        int count = 1;
        
        while (j < nums.size()) 
        {
            // If a new unique element is found while scanning
            if (nums[j] != nums[i]) 
            {
                count++;             // Increase the count
                i++;                 // Move slow pointer to next position
                nums[i] = nums[j];   // Place the unique element there
            }
            
            // Always move the fast pointer forward untill the array is fully scaned
            j++;
        }

        return count;
    }
};


/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    non-decreasing order -> ascending order
*/

/* Question:
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
    each unique element appears only once. The relative order of the elements should be kept the same.

    Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number
    of unique elements k.

    The first k elements of nums should contain the unique numbers in sorted order. The remaining elements
    beyond index k - 1 can be ignored.

    Example 1:
    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,ignored,ignored,ignored,ignored,ignored]
    Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
*/
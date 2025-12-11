#include <bits/stdc++.h>
using namespace std;

/* Approach: Sort using => Frequency Count Vector
*/

/* NOTE: why we cannot use this technique O(n) instead of other sorting Algorithms(O(n log n) ?
   This mapping technic works only when the "set of possible values is known in advance" else 
   you have to create a huge hash map with million possibilities
*/

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // Initialize the freqCountVec of size 3 (red (0), white(1) and blue(2) colours)
        vector<int> freqCountVec(3,0);

        // Iterate the entire input array and capture the frequency count for each colour
        for (auto num : nums)
        {
            freqCountVec[num] = freqCountVec[num] + 1;
        }

        int index = 0;

        // Loop through the freqCountVec, and fill the nums vector as per the frequency count value for each color value
        for (int i = 0; i < freqCountVec.size(); i++)
        {
            while (freqCountVec[i] > 0)
            {
                nums[index] = i;
                index = index + 1;

                freqCountVec[i] = freqCountVec[i] - 1; // reduce the frequency count for each fill in nums array
            }
        }
    }
};

/* Twisted Version: works for any colour value -> (red (5), White(12) and blue(2) colours)
   Use mapping technique -> What every different colour values you get, map it to 0,1,2,3.....
*/

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // Map 5 -> 0, 12 -> 1, 8 -> 2
        unordered_map<int, int> hash;
        hash[5] = 0;
        hash[12] = 1;
        hash[8] = 2;

        vector<int> original = {5, 12, 8};

        // Convert original values to 0,1,2 in nums array
        for (int i=0; i<nums.size(); i++)
        {
            nums[i] = hash[nums[i]];
        }

        // Now your frequency counting sort logic for {0,1,2}
        vector<int> freqCountVec(3);

        for (auto num : nums)
        {
            freqCountVec[num] = freqCountVec[num] + 1; // Increment the counter corresponding to the color value found
        }

        int index = 0;

        // Loop through the freqCountVec, and fill the nums vector as per the frequency count value for each color value
        for (int i = 0; i < freqCountVec.size(); i++)
        {
            while (freqCountVec[i] > 0)
            {
                nums[index] = i;
                index = index + 1;

                freqCountVec[i] = freqCountVec[i] - 1; // reduce the frequency count for each fill in nums array
            }
        }

        // Convert back numbers back to 5,12,8
        for (int i=0; i<nums.size(); i++)
        {
            nums[i] = original[nums[i]];
        }
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    NOTE: why cant we use this technique O(n) instead of other sorting Algorithms(O(n log n) ?
    This mapping technic works only when the "set of possible values is known in advance" else you have
    to create a huge hash map with million possibilities
*/

/* Question: 
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
    of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    Example 1:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Example 2:
    Input: nums = [2,0,1]
    Output: [0,1,2]
*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers -> left(0) and right(size-1)
*/

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right)
        {
            // Calculate current water stored
            int currentWater = min(height[left], height[right]) * (right - left);

            // Update maxWater if this container holds more water
            maxWater = max(maxWater, currentWater);

            // Move the pointer with the smaller height because that is the limiting factor
            if (height[left] < height[right])
            {
                left++;   // try to find a taller left wall
            }
            else
            {
                right--;  // try to find a taller right wall
            }
        }

        return maxWater;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 

*/

/* Question:
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the
    ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store. Notice that you may not slant the container.

    Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:
    Input: height = [1,1]
    Output: 1
*/
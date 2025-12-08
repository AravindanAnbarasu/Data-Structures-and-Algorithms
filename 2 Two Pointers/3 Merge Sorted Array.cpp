#include <bits/stdc++.h>
using namespace std;

/* Approach: Three Right Pointers
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // Assign Pointers:
        int i = m - 1;        // Points to index of last valid element in nums1
        int j = n - 1;        // Points to index of last element in nums2

        int k = m + n - 1;    // Points to index of last position in nums1
        
        /*
            We merge FROM BACKWARDS because nums1 has empty space at the end.
            This avoids overwriting values that are not yet compared.
            
            Idea:
              Compare nums1[i] and nums2[j]
              Place the LARGER one at nums1[k]
        */

        while (i >= 0 && j >= 0) {

            // If nums1 element is bigger, place nums1 at position k
            // Otherwise, If nums2 element is bigger, place nums2 at position k
            if (nums1[i] > nums2[j]) 
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            } 
            else 
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        // If nums2 still has elements left, copy them to final vector nums1
        // (We don't need to copy nums1's remaining elements,
        // because they are already in nums1 which is our final vector)
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }

        // c++ sort : Time complexity O(N log N) : Space complexity O(log N)
        sort(nums1.begin(), nums1.end()); 
    }   
};

/**************************************************************************
 * Time Complexity : O(m + n), m & n are lengths of array nums1 and nums2 *
 * Space Complexity: O(1)                                                 *
 **************************************************************************/

/* Remarks: 
    1. When you start a pointer from right in array or string, always (size - 1), because the
    Index starts from 0

    2. non-decreasing order -> ascending order
*/

/* Question:
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers
    m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
    To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that 
    should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    Example 1:
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
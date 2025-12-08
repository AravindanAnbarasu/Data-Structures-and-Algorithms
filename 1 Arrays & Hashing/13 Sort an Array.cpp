#include <bits/stdc++.h>
using namespace std;

/* Approach: Heap Sort 
*/

class Solution {
public:

    // Function to heapify (create a Max-Heap) a SUB-TREE rooted at index 'i'
    void heapify(vector<int>& nums, int n, int i) {
        
        int pIndex = i;            // Parent index
        // mugUP
        int lIndex = (2 * i) + 1;  // Left child index formula
        int rIndex = (2 * i) + 2;  // Right child index formula

        // If left child exists and is greater than parent
        if (lIndex < n && nums[lIndex] > nums[pIndex])
            pIndex = lIndex;

        // If right child exists and is greater than parent
        if (rIndex < n && nums[rIndex] > nums[pIndex])
            pIndex = rIndex;

        // At this point, the higher number in the sub-tree moves to parent 1index

        // If parent index is modified, swap and continue heapifying untill a leaf-node is found, 
        // which is a Max-Heap by itself
        if (pIndex != i) {
            swap(nums[i], nums[pIndex]);
            heapify(nums, n, pIndex);
        }
        else{
            // Do Nothing. Already a Max-Heap
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Build Max-Heap using Heapify function
        
        // Start from "last" non-leaf node up to root with index 0. Since leaf-nodes are Max-heap by itself
        // Formula to find last non-leaf node in a complete binary tree = n/2
        for (int i = n / 2 - 1; i >= 0; i--) // (n/2 - 1), since array index starts from 0
        {
            heapify(nums, n, i);
        }

        // At this point we have completed constructing a Max-Heap using Heapify function
        // Since we have the Max-Heap formed, the root node is the highest value in the whole tree

        // Step 2: - Loop from the last, and Swap root (highest value) with last element
        //         - Reduce heap size (ignore last sorted element)
        //         - Heapify root index again (to rebuild max heap) 

        for (int i = n - 1; i >= 0; i--) { // n-1 is the last index, since array index starts from 0

            swap(nums[0], nums[i]);

            // Heapify root again index on the reduced size (size = i), size reduced from n to n-1
            heapify(nums, i, 0);
        }

        return nums;
    }
};


/***************************************************
 * Time Complexity : O(n log n)                    *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    1. A Heap is a complete binary tree that follows either min/max heap property. 
    max-heap means: Parent node >= both child nodes

    2. In a complete binary tree all levels are filled except last, and last are filled from
    left to right

    3. A node is called leaf-node, when it doesnot have any children

    4. All leaf-nodes are already Max-Heap by itself

*/

/* Question:
    Given an array of integers nums, sort the array in ascending order and return it.

    You must solve the problem without using any built-in functions in O(nlog(n)) time complexity
    and with the smallest space complexity possible.

    Example 1:
    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
*/
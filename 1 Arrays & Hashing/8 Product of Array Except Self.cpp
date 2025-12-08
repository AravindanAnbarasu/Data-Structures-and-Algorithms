#include <bits/stdc++.h>
using namespace std;

/* Approach: Three-array Method
left[i]	product of all elements to the left of i
right[i] product of all elements to the right of i
Then simply multiply: output[i] = left[i] * right[i]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<int> left(size);
        vector<int> right(size);
        vector<int> output(size);
        
        // left[i] = product of all elements from 0 to i-1
        left[0] = 1;   // base_case: for index 0, there is no left element

        for (int i = 1; i < size; i++) // start from index 1
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // right[i] = product of all elements from size-1 to i+1
        right[size - 1] = 1; // // base_case: for index (size - 1) last index, there is no right element

        for (int i = size - 2; i >= 0; i--) // start from index (size -2)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // Step 3: Multiply left[i] * right[i] to form result
        for (int i = 0; i < size; i++) {
            output[i] = left[i] * right[i];
        }

        return output;
    }
};

/**************************************
 * Time Complexity : O(n)             *
 * Space Complexity: O(n)             *
 **************************************/

/* Remarks: 

    1. VECTOR Thumb Rule: whenever you declare a VECTOR, always initialize with (size, default value)
    or (size) like an array, when you access vec[] first even before push_back. 
    As size of vector<int> vec; -> is Zero.
    
*/

/* Question: 

*/
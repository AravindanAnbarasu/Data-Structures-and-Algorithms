#include <bits/stdc++.h>
using namespace std;

/* Approach: Bit Manipulation
*/

class Solution {
public:
    vector<int> countBits(int n)
    {
        // output vector. n+1 since it holds values from [0, n]
        vector<int> result(n + 1, 0);

        // loop each number from 0 to n
        for (int i = 0; i < n+1 ; i++)
        {
            int count = 0;

            // Check all 32 bits (4 bytes)
            for (int bit = 0; bit < 32; bit++)
            {
                // Extract each bit and check if it is 1 or 0
                if ((i >> bit) & 1)
                {
                    ++count;
                }
            }

            // Store the number of 1-bits for i
            result[i] = count;
        }
        return result;
    }
};

/***************************************************
 * Time Complexity : O(n * 32)  ≈ O(n)             *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given an integer n, count the number of 1's in the binary representation of every number
    in the range [0, n].

    Return an array output where output[i] is the number of 1's in the binary representation of i.

    Example 1:
    Input: n = 4
    Output: [0,1,1,2,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
*/
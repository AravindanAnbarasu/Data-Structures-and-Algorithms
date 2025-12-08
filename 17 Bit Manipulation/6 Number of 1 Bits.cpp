#include <bits/stdc++.h>
using namespace std;

/* Approach: Bit Manipulation
*/

class Solution {
public:
    int hammingWeight(int n)
    {
        int count  = 0;

        // Iterate 32 because int size is 4 bytes/32 bits
        for (int i = 0; i < 32; i++) {

            // Extract each Bit and check if 1 or 0
            if( (n >> i) & 1 ) 
            {
                ++count;
            }
        }
        return count;  
    }
};

/***************************************************
 * Time Complexity : O(1), since 32 bits is fixed  *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given a positive integer n, write a function that returns the number of set bits in its
    binary representation (also known as the Hamming weight).

    Example 1:
    Input: n = 11
    Output: 3
    Explanation:
    The input binary string 1011 has a total of three set bits.

    Example 2:
    Input: n = 128
    Output: 1
    Explanation:
    The input binary string 10000000 has a total of one set bit.
*/
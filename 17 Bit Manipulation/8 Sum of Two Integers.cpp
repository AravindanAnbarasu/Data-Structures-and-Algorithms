#include <bits/stdc++.h>
using namespace std;

/* Approach: Bit Manipulation

    XOR (^) → gives sum without carry
    AND (&) → gives carry bit
    Shift carry left (<< 1) and add again
    Repeat until carry becomes 0
*/

class Solution {
public:
    int getSum(int a, int b) 
    {
        // Repeat until carry becomes 0 
        while (b != 0) 
        {
            // Calculate sum without carry
            int sum = a ^ b;
            
            // Find carry bit
            int carryBit = a & b;
            
            // Move carrybit to the next higher bit
            int carry = carryBit << 1;
            
            // Use new values for next iteration
            a = sum;
            b = carry;
        }
        return a;
    }
};

/***************************************************
 * Time Complexity : O(1), since 32bit integer     *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    a = 5  -> 0101
    b = 3  -> 0011

    Step 1:
    sum = a ^ b = 0110 (6)
    carry = (a & b) = 0001 << 1 = 0010 (2)

    Step 2:
    a = 6, b = 2
    sum = a ^ b = 0100 (4)
    carry = (a & b) = 0010 << 1 = 0100 (4)

    Step 3:
    a = 4, b = 4
    sum = a ^ b = 0000 (0)
    (a & b) = 0100 << 1 = 1000 (8)

    Step 4:
    a = 0, b = 8
    sum = a ^ b = 1000 (8)
    carry = 0  → stop

    Answer = 8
*/

/* Question:
    Given two integers a and b, return the sum of the two integers without using the operators + and -.

    Example 1:
    Input: a = 1, b = 2
    Output: 3

    Example 2:
    Input: a = 2, b = 3
    Output: 5

*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: Bit Manipulation
*/

class Solution {
public:
    uint32_t reverseBits(int n) {

        // Convert signed int → unsigned int. No issues as raw 32 bits still remains the same
        // signed int -5 → binary (2's Complement): 11111111111111111111111111111011
        // Converted to unsigned int-> uint32_t n = 11111111111111111111111111111011
        // But why we need to convert ? Because 
        // Right shift on signed negative numbers: preserves the sign bit.
        // signed int -5 >> 1 becomes, 11111111 11111111 11111111 11111101 (Notice leftmost
        // bit (sign bit) stays 1, not 0.)
        // unsigned int -5 >> 1 becomes, 01111111 11111111 11111111 11111101

        uint32_t num = (uint32_t)n;

        uint32_t reversed = 0;

        // Reverse all 32 bits
        for (int i = 0; i < 32; i++) {

            // Extract LSB bit of num at 0th position
            int lastBit = (num >> i) & 1;

            // Left Shift reversed and make space (LSB becomes MSB Eventually)
            reversed = reversed << 1;    

            // Add last bit to reversed at LSB
            reversed = reversed | lastBit;   
            
        }
        return reversed;
    }
};

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    Right shift on Signed datatype -> "Preserves" the sign bit (MSB)
    Left shift on Signed datatype -> "Do-not" Preserve the sign bit (MSB)
*/

/* Question:
    Reverse bits of a given 32 bits signed integer.

    Example 1:
    Input: n = 43261596
    Output: 964176192
    Explanation:
    Integer	                  Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000

    Example 2:
    Input: n = 2147483644
    Output: 1073741822
    Explanation:
    Integer	                   Binary
    2147483644	01111111111111111111111111111100
    1073741822	00111111111111111111111111111110

*/
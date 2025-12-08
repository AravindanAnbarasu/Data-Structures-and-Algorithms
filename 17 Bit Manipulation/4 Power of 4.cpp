#include <bits/stdc++.h>
using namespace std;

/* Approach: Recursion
Time Complexity : O(log n)                          
Space Complexity: O(log n)  -> recursion depth 
*/
class Solution {
public:
    bool isPowerOfFour(int n) {

        // BaseCase_1: 1 is 4^0 → valid power of 4
        if (n == 1) 
            return true;

        // BaseCase_2: 0 or negative numbers cannot be powers of 4
        if (n <= 0) 
            return false;

        // If n is not divisible by 4, it cannot be a power of 4
        if (n % 4 != 0) 
            return false;

        // Recursive step: reduce the problem size by dividing by 4
        return isPowerOfFour(n / 4);
    }
};

/* Optimal Approach: Bit Manipulation
*/

class Solution {
public:
bool isPowerOfFour(int n) {

    /* Condition1: Base case -> 4^ 0 = 1, so -ve and 0 must be rejected */

    /* Condition2: Checks if n is a power of 2. A power of 2 has exactly one 1-bit
       in whole binary. Ex: 1->0001 ; 2->0010 ; 4->0100 ; 8->1000 ; 16-> 0001 0000 
       Specifically use (n-1), Because subtracting 1 produces the perfect opposite    
       pattern of the original number if Power of 2, Ex: n = 10000 ; n-1  =01111 
       
       This condition is mandatory, because, n = 5 → binary 0101. This is NOT a power
       of 4 But the bit is in a valid even position 
       
       Every power of 4 is automatically a power of 2. But not every power of 2 is 
       a power of 4. */

    /* Condition3: Checks if n is a power of 4. Powers of 4 have 1-bit only 
       at any one of the even positions Example: n = 16 => 0001 0000, 
       so to extract use Mask 0X5 = 0101. For 4 byte integer use => 0x55555555 */

    /* Summary: ✔ Positive number
                ✔ Only one bit set (power of 2)
                ✔ That bit is located at an even index (power of 4)*/
  

    if( (n > 0)  && ((n & (n - 1)) == 0) && ((n & 0x55555555) == n) )
        return true;

    else
        return false;  
    }

};

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
   Given an integer n, return true if it is a power of four. Otherwise, return false.

    An integer n is a power of four, if there exists an integer x such that n == 4^x.

    Example 1:
    Input: n = 16
    Output: true

    Example 2:
    Input: n = 5
    Output: false

    Example 3:
    Input: n = 1
    Output: true
*/
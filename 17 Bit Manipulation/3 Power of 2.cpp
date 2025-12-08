#include <bits/stdc++.h>
using namespace std;

/* Approach Recursion: 
Time Complexity : O(log n)                          
Space Complexity: O(log n)  -> recursion depth 
*/
class Solution {
public:
    bool isPowerOfTwo(long long n) {

        // BaseCase_1: 1 is 2^0 → valid power of 2
        if (n == 1) 
            return true;

        // BaseCase_2: 0 or negative numbers cannot be powers of 2
        if (n <= 0)
            return false;

        // If n is not divisible by 2, it cannot be a power of 2
        if (n % 2 != 0) 
            return false;

        // Recursive step: reduce the problem size by dividing by 2
        return isPowerOfTwo(n / 2);
    }
};

/* Optimal Approach: Bit Manipulation
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

    /* Condition1: Base case -> 2^ 0 = 1, so -ve and 0 must be rejected */

    /* Condition2: Checks if n is a power of 2. A power of 2 has exactly one 1-bit
       in whole binary. Ex: 1->0001 ; 2->0010 ; 4->0100 ; 8->1000 ; 16-> 0001 0000 
       Specifically use (n-1), Because subtracting 1 produces the perfect opposite    
       pattern of the original number if Power of 2, Ex: n = 10000 ; n-1  =01111 */

    if( (n > 0) && ((n & (n - 1)) == 0) )
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
    Given an integer n, return true if it is a power of two. Otherwise, return false.

    An integer n is a power of two, if there exists an integer x such that n == 2^x.

    Example 1:
    Input: n = 1
    Output: true
    Explanation: 2^0 = 1

    Example 2:
    Input: n = 16
    Output: true
    Explanation: 2^4 = 16

    Example 3:
    Input: n = 3
    Output: false
*/
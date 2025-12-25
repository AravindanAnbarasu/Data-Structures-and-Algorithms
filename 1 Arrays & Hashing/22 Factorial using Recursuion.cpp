#include <bits/stdc++.h>
using namespace std;

/* Approach: Factorial using Recursion 
*/

// Recursive function to calculate factorial
int factorial(int n)
{
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
        return 1;

    // Recursive case
    return n * factorial(n - 1);
}

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
      0! = 1
*/

/* Question:
    
*/
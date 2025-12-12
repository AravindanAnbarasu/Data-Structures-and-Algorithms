#include <bits/stdc++.h>
using namespace std;

/* Approach: Bottom-Up Approach / Tabulation 
Time Complexity : O(n)                        
Space Complexity: O(n) 
*/

class Solution {
public:
int climbStairs(int n) {
    // Base_Case: since each time you can either climb 1 or 2 steps 
    if (n <= 2)
        return n;

    vector<int> dp(n + 1);   // index 0 is unused so size = n + 1, instead n
    
    // store the base cases
    dp[1] = 1;
    dp[2] = 2;

    // resuse the stored results and solve your problem
    for (int i = 3; i <= n; i++) // start from 3
    {  
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
    
    }
};


/* Optimal Approach: Bottom-Up Approach (Space-Optimized)
Time Complexity : O(n)                        
Space Complexity: O(1)
*/
class Solution {
public:
    int climbStairs(int n) 
    {
        if (n <= 2)   // Base Case
            return n;
        
        // Store the base case results
        int dp1 = 1;  // No need array, dp[1]
        int dp2 = 2;  // No need array, dp[2]

        int dpn =  0;  // dp[n]
        
        for (int i = 3; i <= n; i++) 
        {
            dpn = dp1 + dp2;  

            dp1 = dp2;       // for next iteration, dp2 becomes dp1
            dp2 = dpn;       // for next iteration, dpn becomes dp2       
        }
    
        return dp2;   // final answer
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
   1. VECTOR Thumb Rule: whenever you declare a VECTOR, always initialize with (size, default value)
   or (size) like an array, when you access vec[] first even before push_back. 
   As size of vector<int> vec; -> is Zero.
*/

/* Question:
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Example 2:
    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
*/


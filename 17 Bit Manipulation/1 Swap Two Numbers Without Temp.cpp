#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void swapNumbers(int &a, int &b) {
        
        // XOR Swap (No temporary variable)
        // mugUP
        
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

 /* Remarks: This solution is a rule as per XOR properties. 
 If they ask to explain, take a sample example and walk through */
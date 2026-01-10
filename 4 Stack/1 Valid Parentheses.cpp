#include <bits/stdc++.h>
using namespace std;

/* Approach: Stack 
*/

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) 
        {
            // if open braces → push
            if (c == '(' || c == '{' || c == '[') 
            {
                st.push(c);
            }

            // if closed bracket
            else 
            {   
                //Base_case: if the 1st bracket is a closed bracket, return false
                if (st.empty())  
                    return false;

                // If matching pair → pop
                if ( c == ')' && st.top() == '(' ||
                     c == '}' && st.top() == '{' ||
                     c == ']' && st.top() == '[' ) 
                {
                    st.pop();
                }
                else 
                {
                    // mismatch case
                    return false;
                }
            }
        }

        return st.empty(); // return true if empty
    }
};


/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    Stack follows LIFO 
*/

/* Question:
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
    string is valid.

    An input string is valid if:
    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.
    - Every close bracket has a corresponding open bracket of the same type.

    Example 1:
    Input: s = "([])"
    Output: true

    Example 2:
    Input: s = "([)]"
    Output: false
*/
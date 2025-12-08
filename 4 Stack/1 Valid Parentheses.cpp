#include <bits/stdc++.h>
using namespace std;

/* Approach: Stack 
*/

class Solution {
public:
    bool isValid(string s) {
        
        //Base_Case: if string is empty, return false
        if(s.length() == 0)
            return false;

        stack<char> st;

        for (char c : s) {

            if (c == '(' || c == '{' || c == '[') // push if any open braces
            {
                st.push(c);
            }

            else // if closed bracket
            {
                if (st.empty())  // if the 1st bracket is a closed bracket, return false
                    return false;

                // If matching pair → pop
                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '[')) 
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
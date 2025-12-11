#include <bits/stdc++.h>
using namespace std;

/* Approach: simple vector
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If list is empty, no common prefix
        if (strs.empty())
            return "";

        string prefix = strs[0]; // Assume entire first string is the prefix

        // Compare prefix with every other string
        for (int i = 1; i < strs.size(); i++) {

            // For every other string, if mismatch occurs, reduce from last and try finding again
            while (strs[i].find(prefix) != 0)
            {
                prefix.pop_back(); // Remove last char

                // If prefix becomes empty -> no common prefix exists
                if (prefix.empty())
                    return "";
            }
        }

        return prefix; // Final common prefix
    }
};

/***********************************************************************************************************
 * Time Complexity : O(n * m), Where n is the length of the shortest string and m is the number of strings *
 * Space Complexity: O(1)                                                                                  *
 ***********************************************************************************************************/

/* Remarks: 
    string.find() returns the position of the first character of the first match.
    If no matches were found, the function returns string::npos.
*/

/* Question:
    You are given an array of strings strs. Return the longest common prefix of all the strings.

    If there is no longest common prefix, return an empty string "".

    Example 1:
    Input: strs = ["bat","bag","bank","band"]
    Output: "ba"

    Example 2:
    Input: strs = ["dance","dag","danger","damage"]
    Output: "da"

    Example 3:
    Input: strs = ["neet","feet"]
    Output: ""
*/
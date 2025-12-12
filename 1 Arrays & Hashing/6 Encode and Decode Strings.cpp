#include <bits/stdc++.h>
using namespace std;

/* Approach: Use length-# prefix encoding
For each string, store its length followed by a delimiter (e.g., #) and then the string itself.
This is to handle cases where strings may contain special characters like # or numbers
Example: ["hello","worl$d"] -> "5#hello6#worl$d"
*/

class Solution {
public:

    // Encodes a list of strings to a single string
    string encode(vector<string>& strs)
    {
        string encoded = "";

        for (auto s : strs) {
            encoded = encoded + to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    // Decodes a single whole string to a list of strings
    vector<string> decode(string s)
    {
        vector<string> decoded;
        int i = 0;              // start iterating using pointer from left

        while (i < s.length())
        {
            // Find the position of '#'
            int hashPOS = i;
            while (s[hashPOS] != '#') {
                hashPOS++;
            }

            // Extract length of the corresponding string
            int length = stoi(s.substr(i, hashPOS - i)); // substr(index, length)

            // Extract the actual string using the length
            string str = s.substr(hashPOS + 1, length);

            decoded.push_back(str);

            // Move pointer 'i' to the start of next encoded part
            i = hashPOS + length + 1;
        }

        return decoded;
    }
};


/***************************************************************************
 * Time Complexity : O(n)                                                 *
 * Space Complexity: O(1)                                                 *
 ***************************************************************************/

/* Remarks: 
   .substr(index, length) 
*/

/* Question:
    271.Encode and Decode Strings (Hidden in LeetCode)
    Design an algorithm to encode a list of strings to a single string. The encoded string is
    then decoded back to the original list of strings.

    Please implement encode and decode
    Example 1:
    Input: ["neet","code","love","you"]
    Output:["neet","code","love","you"]

*/
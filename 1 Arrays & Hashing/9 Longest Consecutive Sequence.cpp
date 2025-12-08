#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        // Base_case: If no numbers, longest sequence is 0
        if (nums.empty()) 
            return 0;

        // Store all numbers into unordered_set for O(1) lookup
        unordered_set<int> numSet;   
        for (int num : nums) {
            numSet.insert(num);
        }

        // Base_case: for an non empty nums, streak is 1
        int longestStreak = 1;

        // Loop through set and check if each number can be a starting point of a sequence.
        // Meaning (num - 1) does NOT exist, it is starting point of a sequence
        for (int num : numSet) {

            if (numSet.find(num - 1) == numSet.end()) 
            {

                int currentNum = num;
                int currentStreak = 1; // at least the current number exists

                // Keep checking for next consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) // next consecutive found
                {
                    currentNum++;
                    currentStreak++;
                }

                // Update longestStreak
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    Each lookup in the Hash table costs only O(1) time 
*/

/* Question: 

*/
#include <bits/stdc++.h>
using namespace std;

/* Approach: naive Sorting
Time Complexity : O(n log n)                          
Space Complexity: O(log n)  
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int missing = 1; // since '1' is the known smallest positive integer
        for (int num : nums) 
        {
            if (missing == num) 
            {
                missing++; // jump to the next smallest positive integer
            }
        }

        return missing;
    }
};

/* Approach: Hash set
Time Complexity : O(n)                          
Space Complexity: O(n)  
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_set<int> hash;

        // Insert only positive numbers into the hash set
        for (int num : nums)
        {
            if (num > 0)
                hash.insert(num);
        }

        int missing = 1; // since '1' is the known smallest positive integer
        while (true)
        {
            if (hash.find(missing) == hash.end())
                return missing;

            missing++;
        }
    }
};

/* Optimal Approach: Sign marking
Time Complexity : O(n)                          
Space Complexity: O(1)   
*/

/* For a given array arr, 
    - The smallest possible integer will only be in the range from {1 to arr.size() + 1}
    - Index i-1 represents number i / Index i represents number i+1
    Example:
    arr = [100, 1, 500], here since the size = 3, missing smallest +ve possible values are 
    [1, 2, 3, 4] no matter what the array contains. Because worst case if array contains
    [1, 2, 3] then the answer is 4. Or if [1,3,4] answer is 2.

    The Possible Array indices are [0, 1, 2, 3] for an Array [1, 2, 3, 4] of size =three 

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Replace useless numbers (<=0 or >n) because they cannot be smallest +ve 
        // We replace invalid useless with (n+1) because it lies outside the range [1,n]
        // and guarantees it won’t affect sign-based marking.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;
        }

        // Step 2: If a number within range is present, mark presence
        for (int i = 0; i < n; i++)
        {
            int val = abs(nums[i]);

            // Mark index (val - 1) as negative if within range, as Index i-1 represents number i
            if (val >= 1 && val <= n)
                nums[val - 1] = -abs(nums[val - 1]);
        }

        // Step 3: First positive index gives the answer
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1; // Index i represents number i+1
        }

        // We only need to detect whether 1 to n exist or not.
        // The absence of all missing numbers in that range automatically implies n + 1.
        return n + 1;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

    You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

    Example 1:
    Input: nums = [1,2,0]

    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.

    Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2
    Explanation: 1 is in the array but 2 is missing.

    Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1
    Explanation: The smallest positive integer 1 is missing.
   
*/
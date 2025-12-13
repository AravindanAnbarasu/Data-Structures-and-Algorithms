#include <bits/stdc++.h>
using namespace std;

/* Approach: Naive Brute-Force
Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        // variable to keep track of number of sub-arrays that equals to k
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = sum + nums[j];

                if (sum == k)
                {
                    result++;
                }
            }
        }
        return result;
    }
};

/* Optimal Approach: Prefix Sum
Time Complexity : O(n)                          
Space Complexity: O(n)
*/

/*
    1. Let prefixSum[i] be the sum of elements from index 0 to i (inclusive).

    2. A sum of a subarray from i to j in an Array sums to k iff:

       prefixSum[j] - prefixSum[i-1] == k
       ⇒ prefixSum[i-1] == prefixSum[j] - k

           Array        -> [1|-3|1|10|1]
                            | |  |  | |
                            v v  v  v v
           prefixSum    -> [1|-2|-1|9|10]

    3. So, while you scan from left to right, for the current prefixSum, you ask:
    "How many prior prefix sums equal prefixSum - k?"

    Each such prior prefixSum, i-1 marks the start of a subarray that ends here at j and sums to k.

    You maintain a hash map that counts how many times each prefix sum has occurred so far.

    Initialize with hash[0] = 1 to count subarrays that start at index 0.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // hash map to store prefixSum : occurance count
        unordered_map<int, int> hash;
        
        // Base_case: If we don’t initialize hash[0] = 1, subarrays that start from index 0 and sum=k
        // will not be counted in result, as there is no recorded prefix sum of 0 to match prefixSum - k
        hash[0] = 1;

        int prefixSum = 0;
        int result = 0;

        // Iterate through the array and capture the prefixSum with its occurance count
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum = prefixSum + nums[i];

            // if (prefixSum - k) is present in hash
            if (hash.find(prefixSum - k) != hash.end())
            {
                result = result + hash[prefixSum - k]; // add how many times (prefixSum - k) has occurred
            }

            // store the prefix sum in hash
            hash[prefixSum] = hash[prefixSum] + 1;
        }

        return result;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 

    1. A subarray is a contiguous non-empty sequence of elements within an array
    meaning [2,1,2] is not a subarray of [2,-1,1,2].

    2. Prefix sum is a technique that involves creating a new array where each element is the
   sum of all elements up to that index in the original array. 

    Array        -> [1|-3|1|10|1]
                     | |  |  | |
                     v v  v  v v
    prefixSum    -> [1|-2|-1|9|10]

    This allows for efficient calculation of the sum of any subarray in constant time O(1),
    after an initial linear time O(n).
    
*/

/* Question:
    Given an array of integers nums and an integer k, return the total number of subarrays whose
    sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2

    Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2
   
*/
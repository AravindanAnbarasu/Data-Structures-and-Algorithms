#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Creat a hash with key: num and value: frequency
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num] = hash[num] + 1;
        }

        // why TwoDVec ?
        // Frequency "1" might have one number, like {1}
        // Frequency "2" might have many numbers, like {2, 5, 6, ...} 

        // + 1 because 0th index is not used, as minimum freq count in hash starts from 1
        vector<vector<int>> TwoDVec(nums.size() + 1);    

        for (auto entry : hash) {

            int number = entry.first;
            int frequency = entry.second;
            TwoDVec[frequency].push_back(number);
        }

        // Loop TwoDVec from high freq to low freq,
        vector<int> result;
        for (int i = TwoDVec.size()-1 ; i >= 1 ; i--) // -1 since index starts from 0
        {
            for (int num : TwoDVec[i]) {
                result.push_back(num);

                if (result.size() == k)   // pick the top k frequent numbers
                    return result;
            }
        }
        return result;
    }
};


/***************************************************************************
 * Time Complexity : O(n)                                                  *
 * Space Complexity: O(n)                                                  *
 ***************************************************************************/

/* Remarks: 

    1. VECTOR Thumb Rule: whenever you declare a VECTOR, always initialize with (size, default value)
    or (size) like an array, when you access vec[] first even before push_back. 
    As size of vector<int> vec; -> is Zero.

    2. hash[c] : You can just insert a key without a value, but the default value 
    of the datatype will be stored. In our case 0, since int
    
*/

/* Question: 

*/
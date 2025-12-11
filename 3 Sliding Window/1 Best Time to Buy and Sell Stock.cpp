#include <bits/stdc++.h>
using namespace std;

/* Approach: Two Pointers (Slow and Fast Pointers)/(Sliding Window), as i and j(window)
slides in every loop.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // 'i' pointer acts as the potential buying day (slow pointer)
        int i = 0;

        // 'j' pointer acts as the potential selling day (fast pointer)
        int j = 1;

        int max_profit = 0;

        // The window slides until the fast pointer reaches the end of the price list.
        while (j < prices.size()) 
        {
            if (prices[i] < prices[j]) // check if selling price is > buying price
            {
                int profit = prices[j] - prices[i]; // calculate the current profit
                max_profit = max(max_profit, profit); // update the Max Profit
            }
            else // if selling price is not > buying price, make the selling price as new buying price
            {
                i = j;
            }

            // Always move the fast pointer forward to explore the next selling day.
            j++;
        }

        return max_profit;
    }
};

/***************************************************
 * Time Complexity : O(n)                          *
 * Space Complexity: O(1)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
    day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, 
    return 0.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.
*/
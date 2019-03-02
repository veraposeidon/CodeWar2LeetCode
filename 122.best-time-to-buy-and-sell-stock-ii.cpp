/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (50.78%)
 * Total Accepted:    292.2K
 * Total Submissions: 574.3K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

// 解决方案，动态规划，修改之前的动态规划方案
// 之前是找最大值sum,现在应该是把sum都累加起来即可。
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        // 0. 边界条件
        if (prices.size() ==0 || prices.empty()) {
            return 0;
        }

        // 1. 动态规划
        int maxSum = 0;
        for(int i = 1; i < prices.size(); i++)
        {   
            // 按照公式推导的确是这样的(high-low) 《（high-low+>high-<high）==(>high-low + high - <high)
            if(prices[i] > prices[i - 1])
                maxSum += (prices[i] - prices[i - 1]);
        }
    return maxSum; 
    }
};

// 解决方案二：峰谷方法
// : Total Profit= 所有的相邻的（peak-valley）
// 所以方案就是找相邻的
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0. 边界条件
        if (prices.size() ==0 || prices.empty()) {
            return 0;
        }

        // 峰谷
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            // 找峰谷，停止降低的地方
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            
            valley = prices[i];

            // 找峰谷，停止升高的地方
            while (i < prices.size()  - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];

            // 累加
            maxprofit += peak - valley;

        }

        return maxprofit;
    }
};

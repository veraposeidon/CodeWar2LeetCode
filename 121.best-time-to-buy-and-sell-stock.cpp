/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (46.10%)
 * Total Accepted:    437.6K
 * Total Submissions: 947.3K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */

// 解决方案一：分治法
// 同样分三个区间，解决哪个区域的赚的最多的问题
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        // 0. 边界条件
        if (prices.size() ==0 || prices.empty()) {
            return 0;
        }

        // 1. 调用分治
        int result = whereMax(prices, 0, prices.size()-1);

        // 2. 返回结果
        return result;  
    }

    // 分治忌讳忘记返回结果
    int whereMax(vector<int>& prices, int dayStart, int dayEnd)
    {
        // 返回条件需要考虑，不能只分到一天，在两天时就返回一个赚钱的数
        if((dayEnd - dayStart) == 1)
            return prices[dayEnd]>prices[dayStart]?prices[dayEnd]-prices[dayStart]:0;
        
        // 只分到一天的时候，就返回零即可。
        if (dayEnd == dayStart) {
            return 0;
        }
        

        int mid = (dayStart + dayEnd) / 2;
        
        // 左边区域
        int left = whereMax(prices, dayStart, mid);
        // 右边区域
        int right = whereMax(prices, mid+1, dayEnd);

        // 跨区域，既然是跨区域，那必须买在前面，卖在后面。前面价格越低越好，后面价格越高越好
        // 就转换成找前面最小值，后面最大值即可
        int leftmin = prices[mid];
        for(int i = dayStart; i <= mid; i++)
        {
            if (prices[i] < leftmin) {
                leftmin = prices[i];
            } 
        }
        int rightmax = prices[mid+1];
        for(int i = mid+1; i <= dayEnd; i++)
        {
            if (prices[i] > rightmax) {
                rightmax = prices[i];
            } 
        }
        
        // 跨区域最大值
        int center = 0;
        if (rightmax > leftmin) {
            center = rightmax - leftmin;
        }
        
        // 比大小
        if (left > center) {
            center = left;
        }

        if(center > right)
        {
            right = center;
        }
        
        return right;
    }
};


// 解法二：动态规划
// 实在厉害：把j-i转换成j-(j-1) + (j-1)-i这样子的累加
// 从而通过找到最大值即找到了最大的差值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0. 边界条件
        if (prices.size() ==0 || prices.empty())
            return 0;

        // 1. 动态规划
        int sumi = 0, maxSum = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            sumi += prices[i] - prices[i-1];
            sumi = max(sumi, 0);    // 这里的意思是，如果累加和小于0，那意味着前n个没有可赚的。仔细观察数列会发现，除非最小的数被取代了，否者前面的累加一直都有意义。
            maxSum = max(maxSum,sumi);   // 全局最大值
        }
    return maxSum;
    }
};



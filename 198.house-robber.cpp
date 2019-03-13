/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.78%)
 * Total Accepted:    294.5K
 * Total Submissions: 721.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */


// 动态规划，还是把问题抛给了最优子结构
// 当前最大利润 = max(上回利润， 上上回利润+本次收益)
class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() ) {
            return 0;
        }

        int maxprofit = 0;

        int lastmaxprofit = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int now = max(maxprofit, lastmaxprofit + nums[i]);
            lastmaxprofit = maxprofit;
            maxprofit = now;   
        }
        
        return maxprofit;
        
    }
};


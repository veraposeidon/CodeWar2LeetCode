/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i< dp.size(); i++) {
            for (int coin : coins) {
                if (i - coin < 0) continue;
                if (i - coin == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }   
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N + 2, vector<int>(N + 2));
        vector<int> val(N + 2);
        val[0] = 1, val[N + 1] = 1;
        for (int i = 1; i <= N; i++) {
            val[i] = nums[i - 1];
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 2; j <= N + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][N+1];
    }
};
// @lc code=end


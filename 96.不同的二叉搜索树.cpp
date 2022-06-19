/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        auto dp = vector<int>(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
    

    // 卡塔兰数
    // int numTrees(int n) {
    //     long long c = 1;  // c0 = 1;
    //     for (int i = 0; i < n; i++) {
    //         c = c * 2 * (2 * i + 1) / (i + 2);
    //     }
 
    //     return c;
    // }
};
// @lc code=end


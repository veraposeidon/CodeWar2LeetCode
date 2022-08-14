/*
 * @lc app=leetcode.cn id=309 lang=swift
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        guard prices.count > 1 else {
            return 0
        }
        let n = prices.count
        var dp = [[Int]](repeating: [Int](repeating: 0, count: 3), count: n)
        
        dp[0][0] = -prices[0]
        dp[0][1] = 0
        dp[0][2] = 0

        for i in 1..<n {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])
            dp[i][1] = dp[i-1][0] + prices[i]
            dp[i][2] = max(dp[i-1][2], dp[i-1][1])
        }

        return max(dp[n-1][0], dp[n-1][1], dp[n-1][2])
    }
}
// @lc code=end


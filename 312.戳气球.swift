/*
 * @lc app=leetcode.cn id=312 lang=swift
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
    func maxCoins(_ nums: [Int]) -> Int {
        let N = nums.count
        var dp = [[Int]](repeating: [Int](repeating: 0, count: N + 2), count: N + 2)
        var val = [Int](repeating: 1, count: N + 2)
        val[0] = 1
        val[N+1] = 1
        for i in 1...N {
            val[i] = nums[i-1]
        }

        for i in (0...(N-1)).reversed() {
            for j in (i+2)...(N+1) {
                for k in (i+1)...(j-1) {
                    var sum = val[i] * val[k] * val[j]
                    sum += dp[i][k] + dp[k][j]
                    dp[i][j] = max(dp[i][j], sum)
                }
            }
        }
        return dp[0][N+1]
    }
}
// @lc code=end


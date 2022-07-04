// swiftlint:disable identifier_name trailing_newline
/*
 * @lc app=leetcode.cn id=139 lang=swift
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        let size = s.count
        var dp = Array(repeating: false, count: size + 1)
        dp[0] = true
        for i in 0...size {
            if !dp[i] { continue }
            for word in wordDict {
                let len = word.count
                if i + len > size { continue }
                let startIndex = s.index(s.startIndex, offsetBy: i)
                let endIndex = s.index(s.startIndex, offsetBy: i + len - 1)

                if s[startIndex...endIndex] == word { dp[i+len] = dp[i+len] || true }
            }
        }
        return dp[size]
    }
}
// @lc code=end


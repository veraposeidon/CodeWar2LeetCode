/*
 * @lc app=leetcode.cn id=338 lang=swift
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
    func countBits(_ n: Int) -> [Int] {
        var res = [Int](repeating: 0, count: n + 1)
        for idx in 0...n {
            res[idx] = countBit(idx)
        }
        return res
    }

    func countBit(_ n: Int) -> Int {
        var res = 0
        var x = n
        while x > 0 {
            x = x & (x - 1)
            res += 1
        }
        return res
    }
}
// @lc code=end

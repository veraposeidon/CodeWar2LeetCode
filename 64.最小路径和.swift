/*
 * @lc app=leetcode.cn id=64 lang=swift
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
    func minPathSum(_ grid: [[Int]]) -> Int {
        let rows = grid.count
        let cols = grid[0].count
        var dps = Array(repeating: Array(repeating: 0, count: cols), count: rows)
        dps[0][0] = grid[0][0]
        for idx in 1..<rows {
            dps[idx][0] = dps[idx-1][0] + grid[idx][0]
        }
        for idx in 1..<cols {
            dps[0][idx] = dps[0][idx-1] + grid[0][idx]
        }
        for index in 1..<rows {
            for jndex in 1..<cols {
                dps[index][jndex] = min(dps[index-1][jndex], dps[index][jndex-1]) + grid[index][jndex]
            }
        }
        return dps[rows-1][cols-1]
    }
}
// @lc code=end
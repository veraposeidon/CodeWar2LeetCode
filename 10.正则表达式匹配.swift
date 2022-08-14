/*
 * @lc app=leetcode.cn id=10 lang=swift
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
    func isMatch(_ s: String, _ p: String) -> Bool {
        let s = Array(s)
        let p = Array(p)
        let mSize = s.count, nSize = p.count

        let compare = { (idx: Int, jdx: Int) -> Bool in
            if idx == 0 {
                return false
            }
            if p[jdx-1] == "." {
                return true
            }
            return s[idx - 1] == p[jdx - 1]
        }

        var dpTb = [[Bool]](repeating: [Bool](repeating: false, count: nSize + 1), count: mSize + 1)
        dpTb[0][0] = true
        for idx in 0...mSize {
            for jdx in 1...nSize {
                if p[jdx - 1] == "*" {
                    dpTb[idx][jdx] = dpTb[idx][jdx] || dpTb[idx][jdx - 2]
                    if compare(idx, jdx - 1) {
                        dpTb[idx][jdx] = dpTb[idx][jdx] || dpTb[idx - 1][jdx]
                    } 
                } else {
                    if compare(idx, jdx) {
                        dpTb[idx][jdx] = dpTb[idx][jdx] || dpTb[idx - 1][jdx - 1]
                    }
                }
            }
        }
        return dpTb[mSize][nSize]
    }
}
// @lc code=end


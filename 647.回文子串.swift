/*
 * @lc app=leetcode.cn id=647 lang=swift
 *
 * [647] 回文子串
 */

// @lc code=start

// 这种方式不如将 string 转换成 [char] 的方式
// extension StringProtocol {
//     subscript(offset: Int) -> Character {
//         return self[index(startIndex, offsetBy: offset)]
//     }
// }

class Solution {
    func countSubstrings(_ s: String) -> Int {
        let sa = Array(s)
        var len = sa.count
        var dpt: [[Bool]] = Array(repeating: Array(repeating: false, count: len), count: len)
        var res = 0
        for right in 0..<len {
            for left in 0...right {
                if (sa[left] == sa[right]) && (right - left < 2 || dpt[left+1][right-1]) {
                    dpt[left][right] = true
                    res += 1
                }
            }
        }
        return res
    }
}
// @lc code=end

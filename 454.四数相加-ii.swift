/*
 * @lc app=leetcode.cn id=454 lang=swift
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
    func fourSumCount(_ A: [Int], _ B: [Int], _ C: [Int], _ D: [Int]) -> Int {
        var dictAB = [Int: Int]()
        for a in A {
            for b in B {
                let sum = a + b
                dictAB[sum, default: 0] += 1
            }
        }
        var count = 0
        for c in C {
            for d in D {
                let sum = 0 - c - d
                if let cnt = dictAB[sum] {
                    count += cnt
                }
            }
        }
        return count
    }
}
// @lc code=end


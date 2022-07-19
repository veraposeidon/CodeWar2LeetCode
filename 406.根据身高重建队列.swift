/*
 * @lc app=leetcode.cn id=406 lang=swift
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
    func reconstructQueue(_ people: [[Int]]) -> [[Int]] {
        var peoples = people.sorted(by: { (lhs, rhs) -> Bool in
            if lhs[0] == rhs[0] {
                return lhs[1] < rhs[1]
            } else {
                return lhs[0] > rhs[0]
            }
        })
        var res = [[Int]]()
        for person in peoples {
            res.insert(person, at: person[1])
        }
        return res
    }
}
// @lc code=end

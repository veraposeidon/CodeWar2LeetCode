/*
 * @lc app=leetcode.cn id=39 lang=swift
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    var res = [[Int]]()

    func dfs(_ candidates: [Int], _ startPos: Int, _ target: Int, _ cur: inout [Int]) {
        if target == 0 {
            res.append(cur)
            return
        }
        for idx in startPos..<candidates.count {
            guard target >= candidates[idx] else {
                continue
            }
            cur.append(candidates[idx])
            dfs(candidates, idx, target - candidates[idx], &cur)
            cur.removeLast()
        }
    }

    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var candidatesCopy = candidates
        candidatesCopy.sort(by: <)
        var cur = [Int]()
        dfs(candidatesCopy, 0, target, &cur)
        return res
    }
}
// @lc code=end
/*
 * @lc app=leetcode.cn id=337 lang=swift
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func dfs(_ root: TreeNode?) -> (Int, Int) {
        guard let root = root else {
            return (0, 0)
        }
        let (leftF, leftG) = dfs(root.left)
        let (rightF, rightG) = dfs(root.right)
        let curF = leftG + rightG + root.val
        let curG = max(leftF, leftG) + max(rightF, rightG)
        return (curF, curG)
    }

    func rob(_ root: TreeNode?) -> Int {
        let (curF, curG) = dfs(root)
        return max(curF, curG)
    }
}
// @lc code=end


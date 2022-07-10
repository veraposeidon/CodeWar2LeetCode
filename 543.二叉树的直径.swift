/*
 * @lc app=leetcode.cn id=543 lang=swift
 *
 * [543] 二叉树的直径
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
    var maxLen = 0

    func findMax(_ root: TreeNode?) -> Int {
        if root == nil { return 0}

        var left = findMax(root!.left)
        var right = findMax(root!.right)

        if left + right > maxLen {
            maxLen = left + right
        }

        return max(left, right) + 1
    }

    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        findMax(root)
        return maxLen
    }
}
// @lc code=end


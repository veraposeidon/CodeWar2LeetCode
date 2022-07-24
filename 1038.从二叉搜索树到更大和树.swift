/*
 * @lc app=leetcode.cn id=1038 lang=swift
 *
 * [1038] 从二叉搜索树到更大和树
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
    var sum = 0
    func bstToGst(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else {
            return nil
        }
        bstToGst(root.right)
        sum += root.val
        root.val = sum
        bstToGst(root.left)
        return root
    }
}
// @lc code=end

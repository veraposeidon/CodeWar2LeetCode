/*
 * @lc app=leetcode.cn id=538 lang=swift
 *
 * [538] 把二叉搜索树转换为累加树
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
    // 二叉搜索树的中序遍历是递增的，而题目要求大于等于累加和，可以用反序中序遍历的方式来解决
    // 即构建递减序列，累计sum
    var sum = 0

    func convertBST(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else {
            return nil
        }
        convertBST(root.right)
        sum += root.val
        root.val = sum
        convertBST(root.left)
        return root
    }
}
// @lc code=end

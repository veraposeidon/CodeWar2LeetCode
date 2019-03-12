/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.85%)
 * Total Accepted:    276.5K
 * Total Submissions: 792.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 思路：递归解法
// 计算左右子树的深度，取较小值，+1得到当前节点到低端的最小长度
// 需要注意的是，必须要一个节点的两片叶子都不存在才为leaf node.
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 0. 递归终止
        if (root == NULL) {
            return 0;
        }

        // 1. 左右子树长度

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        // 2. 需要判断是否都为零

        return left&&right ? min(left,right)+1 : max(left, right)+1; 
    }
};


/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = INT_MIN;
    int maxSide(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, maxSide(root->left));
        int right = max(0, maxSide(root->right));

        result = max(result, root->val + left + right);    // 联结左右
        return max(left, right) + root->val;
    }
    // 后序遍历
    int maxPathSum(TreeNode* root) {
        return max(result, maxSide(root)); 
    }
};
// @lc code=end


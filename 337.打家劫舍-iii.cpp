/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*, int> f, g; // f 表示包含当前节点， g 表示不包含当前节点

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        dfs(root->right);

        f[root] = g[root->left] + g[root->right] + root->val;
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(g[root], f[root]);
    }
};
// @lc code=end


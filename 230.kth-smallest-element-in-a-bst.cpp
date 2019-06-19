/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历（深度优先）
        dfs(root);

        return list[k-1];
    }

    vector<int> list;
    void dfs(TreeNode* root){
        if(root ==NULL){
            return ;
        }

        dfs(root->left);
        list.push_back(root->val);
        dfs(root->right);
    }
};


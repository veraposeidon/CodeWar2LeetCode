/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    // 自顶向下
    // 自底向上
    // 公共路径的最后一个节点
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(has_node(root->left, p) && has_node(root->left, q)){ // 都在左子树
            return lowestCommonAncestor(root->left, p, q);
        }else if(has_node(root->right, p) && has_node(root->right, q)){ // 都在左子树
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
    }
    
    bool has_node(TreeNode* root, TreeNode* target) {
        if(root==NULL) return false;
        if(root==target) return true;
        return has_node(root->left, target) || has_node(root->right, target);
    }
};


/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right!=NULL) root=root->right;
        root->right = temp;        
    } 
};


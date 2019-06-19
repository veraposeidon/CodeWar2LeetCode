/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxsum_root = INT_MIN;
    int maxPathSum(TreeNode* root) {
        // 0. check
        if(root==NULL){
            // 空节点
            return 0;
        }
        maxPath(root);
        return maxsum_root; 
    }


    int maxPath(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int left_max = maxPath(root->left);
        int right_max = maxPath(root->right);

        maxsum_root = max(maxsum_root, max(0,left_max)+max(0,right_max)+root->val);
        return max(0,max(left_max,right_max)+root->val);
    }
};


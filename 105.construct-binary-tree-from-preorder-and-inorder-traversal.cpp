/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// 应该还是用递归的方式来解决
// 第一个节点为根节点
// 分左右的前序和中序遍历
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 0. 空节点
        if(preorder.empty() || inorder.empty()){
            return NULL;
        }

        // 1. 前序的第一个节点作为根节点
        int val = preorder[0];
        TreeNode *root = new TreeNode(val);
        // 2. 找到中序遍历中的根节点
        int root_pos;
        for (int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == val){
                root_pos = i;
                break;
            }
        }

        // 这种方式太耗时间了，可以换成用下标记录的方式
        vector<int> left_preorder(preorder.begin()+1,preorder.begin()+1+root_pos);
        vector<int> left_inorder(inorder.begin(),inorder.begin()+root_pos);
        vector<int> right_preorder(preorder.begin()+1+root_pos,preorder.end());
        vector<int> right_inorder(inorder.begin()+root_pos+1,inorder.end());
        
        root->left  = buildTree(left_preorder,left_inorder);
        root->right = buildTree(right_preorder,right_inorder);
        return root;
    }
};


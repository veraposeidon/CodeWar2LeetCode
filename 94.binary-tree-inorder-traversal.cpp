/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
// 中序遍历 左根右

// 解法一：先用递归解法
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 0. check null
        if (root == NULL)
        {
            return vector<int>(0);
        }

        vector<int> result(0);
        recursive(root, result);

        return result;
    }

    void recursive(TreeNode* root,vector<int>&result){
        if(root == NULL){
            return ;
        }

        recursive(root->left, result);
        result.push_back(root->val);
        recursive(root->right, result);
    }
};

// 使用stack进行迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 0. check null
        if (root == NULL)
        {
            return vector<int>(0);
        }

        vector<int> result;
        stack<TreeNode*> stacks;
        TreeNode* node=root;

        while (node!=NULL || !stacks.empty())
        {
            // 针对当前节点，有左节点就压左节点
            while(node!=NULL){
                stacks.push(node);
                node = node->left;
            }
            
            // 直到没有左节点，弹出，打印当前节点
            if (!stacks.empty())
            {
                node = stacks.top();    // 打印当前节点
                result.push_back(node->val);
                stacks.pop();
                node = node->right;
            }
        }

        return result;
    }
};


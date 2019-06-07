/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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

// 思路一：层序遍历 + 反向输出
// 但是层序遍历会没法直接判断到了第几层，可以用两个栈来相互存储。
// 反向的话可以用左右子树的切换来实现。 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if ( root == NULL )
        {
            return result;
        }
        
        stack<TreeNode* > sig;
        stack<TreeNode* > dbl;
        sig.push(root);
        vector<int> out;
        while (!sig.empty() || !dbl.empty())
        {   
            out.clear();
            while ( !sig.empty())
            {
                TreeNode *cur = sig.top();
                sig.pop();

                out.push_back(cur->val);
                if(cur->left){
                    dbl.push(cur->left);
                }
                if(cur->right){
                    dbl.push(cur->right);
                }
            }
            if (!out.empty()){
                result.push_back(out);
            }

            out.clear();
            while ( !dbl.empty() )
            {
                TreeNode *cur = dbl.top();
                dbl.pop();

                out.push_back(cur->val);
                if(cur->right){
                    sig.push(cur->right);
                }
                if(cur->left){
                    sig.push(cur->left);
                }
            }   
            if (!out.empty()){
                result.push_back(out);
            }
        }
        return result;
    }
};


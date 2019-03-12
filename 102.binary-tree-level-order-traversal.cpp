/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (47.03%)
 * Total Accepted:    341.7K
 * Total Submissions: 724.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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

// 层次遍历简单啊，就是用队列进行广度优先搜索嘛。
// 迭代解法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 0. 
        if (root == NULL) {
            return vector<vector<int>>(0);
        }
        
        vector<vector<int>> result(0);
        TreeNode* node = root;
        queue<TreeNode*> que;
        que.push(node); // 先压入根节点

        while(!que.empty()){
            vector<int> tmp(0);
            for(int i = 0, n = que.size(); i < n; i++)
            {
                // 遍历前一层所有节点
                TreeNode* nodetmp = que.front();
                que.pop();
                tmp.push_back(nodetmp->val);

                // 压入下一层所有节点
                if (nodetmp->left != NULL) {
                    que.push(nodetmp->left);
                }
                
                if (nodetmp->right != NULL) {
                    que.push(nodetmp->right);
                }
            }
            result.push_back(tmp);
        }
        
        return result;
    }
};


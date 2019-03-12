/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (37.03%)
 * Total Accepted:    289.5K
 * Total Submissions: 780.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

// 递归解法
// 向下遍历累减，大于零继续 ， 小于零返回false, null返回false, ==sum 返回true
// 上述思路有问题，问题是root-to-leaf path，即必须要累加到没有子节点时相等才算true
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        int val = sum - root->val;

        if ( val == 0 && root->left == NULL && root->right == NULL) {
            return true;
        }
        // else if ( val != 0 && root->left == NULL && root->right == NULL ) {
        //     return false;
        // }
        else
        {
            return hasPathSum(root->left, val) || hasPathSum(root->right, val);
        }
        
        return false;
    }
};


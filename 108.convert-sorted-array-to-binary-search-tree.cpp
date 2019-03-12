/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.25%)
 * Total Accepted:    241.1K
 * Total Submissions: 488.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

// 平衡二叉树，那就使用分治法构建好了。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 0.
        if (nums.empty()) {
            return NULL;
        }       
        
        // 1. 
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid]);   // 新数据记得要实例化
        node->left = sortedArrayToBST(nums, low, mid-1);
        node->right = sortedArrayToBST(nums, mid+1, high);

        return node;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) 
    {   
        // 分治边界
        if (low == high) {
            return new TreeNode(nums[low]);
        }else if (low > high) {
            return NULL;
        }
        
        // 
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, low, mid-1);
        node->right = sortedArrayToBST(nums, mid+1, high);

        return node;
        
    }
};


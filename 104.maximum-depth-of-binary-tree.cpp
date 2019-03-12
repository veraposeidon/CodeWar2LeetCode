/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (59.19%)
 * Total Accepted:    462.1K
 * Total Submissions: 778.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its depth = 3.
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

// 递归解法: 深度优先搜索
// 时间复杂度O(n)
// 空间复杂度O(n)
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if ( root == NULL ) {
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left,right)+1;
    }
};

// 广度优先搜索：使用队列进行迭代解法
// 广度优先快
// 时间复杂度：o(n)
// 空间复杂度：o(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( root == NULL ) {
            return 0;
        }
        
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);

        // 大意就是每次都把当前层的所有节点的左右子树压入，下次把所有队列中的节点都弹出。即每次都清空上一层节点，压入下一层节点。
        while(!q.empty()){
            ++res;

            // 注意这里的n表示上一轮的压入数目，不能挪用。
            for(int i = 0, n = q.size(); i < n; i++)
            {
                TreeNode* p = q.front();
                q.pop();

                if (p->left !=NULL) {
                    q.push(p->left);
                }

                if (p->right !=NULL){
                    q.push(p->right);
                }   
            }
        }
        
        return res;
    }
};


/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.71%)
 * Total Accepted:    364.6K
 * Total Submissions: 851.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
// 时间复杂度：O(n).与每个节点都进行了比较，因此为O(n)
// 空间复杂度：O(n).与树的高度有关，最差的情况就是树的大小等于树的高度。
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if ( root == NULL) {
            true;
        } 
        
        return recursive(root, root);
    }

    bool recursive(TreeNode* left, TreeNode* right)
    {
        // 递归终止条件
        if ( left == NULL && right == NULL ) {
            return true;
        }
        // 递归终止条件
        if ( left == NULL || right == NULL ){
            return false;
        }
        // 判断节点值
        if ( left->val != right->val ){
            return false;
        }
        // 判断左子树和右子树的对称
        bool leftB  = recursive( left->left, right->right );
        bool rightB = recursive( left->right, right->left );

        return leftB && rightB;
    }
};


// 迭代解法
// 把树按照顺序推进序列，队列弹出元素进行比较。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *left,*right;
        if( root == NULL )
            return true;

        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);

        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();

            right = q2.front();
            q2.pop();

            if ( NULL == left && NULL ==right ) {
                continue;
            }

            if ( NULL == left || NULL == right )
            {
                return false;
            }
            if ( left->val != right->val ) {
                return false;
            }

            // 一次分别压入两颗子树
            // 并不表示同时处理，需要将一颗子树的子树解决之后才解决另外一颗子树
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }

        return true;
        
    }
};
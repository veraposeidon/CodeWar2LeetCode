/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.44%)
 * Total Accepted:    260.4K
 * Total Submissions: 597.6K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
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

// 思路：
// 首先每个值都是独立的。因此遍历是可行的。
// 其次，两个值都存在于树中，因此一定遍历得到。
// 最重要的是这是一颗二分查找树。所以节点都是排序的。
// 也就是说，如果一个数在节点右侧，一个在左侧，则该节点就是最小公共节点了。
// 
// 递归解法：
// 时间复杂度：O(n)。最坏情况需要遍历所有节点。
// 空间复杂度：O(n)。递归栈空间与树的高度有关。最坏情况为n。
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 0.
        if ( root == NULL || p == NULL || q == NULL ) {
            return NULL;
        }

        // 分列两侧，则返回该节点
        if ( p->val < root->val && q->val < root->val ) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        if ( p->val > root->val && q->val > root->val ) {
            return lowestCommonAncestor(root->right, p ,q);
        }

        // 其他情况返回当前节点。
        return root;

    }
};

// 迭代法
// 因为只需要找到分割点即可，因此迭代找到即可，并不一定需要递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 0.
        if ( root == NULL || p == NULL || q == NULL ) {
            return NULL;
        }

        // 1. 
        int qVal = q->val;
        int pVal = p->val;
        TreeNode* node = root;
        
        while( node != NULL ){
            if ( qVal < node->val && pVal < node->val ) {
                node = node->left;
            }else if ( qVal > node->val && pVal > node->val ) {
                node = node->right;
            }else
            {
                return node;
            } 
        }

        return root;
    }
};

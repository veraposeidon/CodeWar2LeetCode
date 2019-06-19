/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        
        Node* dummy = root;
        
        Node* left = connect(root->left);   // 对左子树进行操作
        Node* right = connect(root->right); // 对右子树进行操作
        
        
        while(left!=NULL && right!=NULL){
            left->next = right; // 进行链接
            // 下沉链接 左右两个子树
            left=left->right;   
            right=right->left;
        }
        
        
        return dummy;
    }
};


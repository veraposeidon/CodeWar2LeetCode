/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // 层序遍历
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        vector<string> result;
        while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            result.push_back(node==NULL?"null":to_string(node->val));
            if(node){
                queue.push(node->left);
                queue.push(node->right);
            }
        }

        stringstream ss;
        for (int i = 0; i < result.size(); i++)
        {
            if(i!=0){
                ss << ",";
            }

            ss << result[i];
        }
        return ss.str();
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> strs;
        while (ss.good())
        {
            string buffer;
            getline(ss, buffer, ',');
            strs.push(buffer);
        }

        if(strs.empty()) return NULL;

        queue<TreeNode*> queue;
        string val = strs.front();
        strs.pop();
        TreeNode* root = val=="null"?NULL:new TreeNode(stoi(val));
        if(root==NULL) return root;
        queue.push(root);
        while (!queue.empty())
        {
            TreeNode* tr = queue.front();
            queue.pop();
            
            val = strs.front();
            strs.pop();
            tr->left = val=="null"?NULL:new TreeNode(stoi(val));
            if(tr->left) queue.push(tr->left);
            if(strs.empty()) break; 

            val = strs.front();
            strs.pop();
            tr->right = val=="null"?NULL:new TreeNode(stoi(val));
            if(tr->right) queue.push(tr->right);
            if(strs.empty()) break; 
        }    
        return root;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


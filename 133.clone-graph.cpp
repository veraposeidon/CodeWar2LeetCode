/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    // DFS // 注意
    // hash_map ID对应节点Node
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return DFS(node, map);
    }
    
    Node* DFS(Node* node, unordered_map<Node*, Node*>&map){
        // 递归结束条件
        if(node==NULL) return NULL; // 空
        if(map.count(node)) return map[node];    // 存在
        Node* clone = new Node(node->val);  // 创建新节点
        map[node] = clone;  // 注册旧节点对应新节点
        for(Node* neighbor : node->neighbors){
            clone->neighbors.push_back(DFS(neighbor, map));
        }
        return clone;
    }
};

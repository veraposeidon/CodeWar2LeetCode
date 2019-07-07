/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */
class Solution {
public:
    // 相似：数岛屿数目
    // 深度优先搜索,跟标地雷一样标记一遍即可
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        for(int i=0;i<M.size();i++){
            if(M[i][i] == 1){
                dfs(M, i);
                count ++;
            }

        }
        
        return count;
        
    }
    
    // 遍历第i个人的情况
    void dfs(vector<vector<int>>& M, int i){
        if(i<0 || i>=M.size()) return;
        if(M[i][i] = 0)  return;
        
        M[i][i] = 0;
        for(int j=0;j<M.size();j++){
            if(M[i][j] == 1){
                M[i][j] = 0;
                M[j][i] = 0;
                dfs(M, j);
            }
        }
    }
};

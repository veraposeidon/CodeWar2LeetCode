/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
class Solution {
public:
    // 从0出发，DFS搜索 // DFS 超时 // 换BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }else{
                    matrix[i][j]=INT_MAX;
                }
            }
        }
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            for(auto dir : dirs){
                int x = t.first + dir[0], y = t.second+dir[1];
                if(x<0||x>=rows||y<0||y>=cols) continue;
                if(matrix[x][y] <= matrix[t.first][t.second]+1) continue;
                matrix[x][y] = matrix[t.first][t.second]+1;
                q.push({x,y});
            }
        }
        
        return matrix;
    }
    
//     void dfs(vector<vector<int>>& matrix, vector<vector<int>> &result, int i, int j, int step){
//         int rows=matrix.size(),cols=matrix[0].size(); 
//         // 终止条件
//         if(i<0||i>=rows||j<0||j>=cols) return;
        
//         if(matrix[i][j] == 1){
//             if(result[i][j] < step) return; // 早已有人来过   
            
//             result[i][j] = step;
//         }else{
//             if(step!=0) return;
//         }
//         // 继续探索
//         dfs(matrix, result, i+1, j, step+1);
//         dfs(matrix, result, i-1, j, step+1);
//         dfs(matrix, result, i, j+1, step+1);
//         dfs(matrix, result, i, j-1, step+1);
//     }
    
};


/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
class Solution {
public:
    int max_size = 0;
    // 尝试使用深度优先遍历
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        vector<vector<bool>> visted(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                max_size = max(max_size, dfs(grid, visted, i, j));
            }
        }
        
        return max_size;
    }
    
    int dfs(const vector<vector<int>>& grid,vector<vector<bool>>& visted, int x, int y){
        
        // 结束条件
        if(x<0||x>=grid.size()|| y<0||y>=grid[0].size()){
            return 0;
        }
        // 结束条件 
        if(grid[x][y] == 0 || visted[x][y]){
            // max_size = max(max_size, count);
            return 0;
        }
        
        int count = 1;
        visted[x][y] = true;    // 不需要重置回去，因为访问过了就是访问过了，只需要访问一遍即可。
        count += dfs(grid, visted, x+1, y);
        count += dfs(grid, visted, x-1, y);
        count += dfs(grid, visted, x, y+1);
        count += dfs(grid, visted, x, y-1);
        return count;
    }
};

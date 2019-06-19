/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
// 深度优先遍历
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 0. check
        if(grid.empty()){
            return 0;
        }

        // 1. 
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int count=0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs_search(grid, visited, i,j);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs_search(vector<vector<char>>& grid, vector<vector<bool>> &visited, int x, int y){
        if(x<0||x>=grid.size()){
            return;
        }
        if(y<0||y>=grid[0].size()){
            return;
        }

        if(grid[x][y] != '1' || visited[x][y]){
            return;
        }

        visited[x][y] = true;
        dfs_search(grid, visited, x-1,y);
        dfs_search(grid, visited, x+1,y);
        dfs_search(grid, visited, x,y-1);
        dfs_search(grid, visited, x,y+1);
    }
};


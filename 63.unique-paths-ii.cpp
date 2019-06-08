/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// 动态规划
// 构建DP数组
// 初始化行和列
// 遇到障碍则设为0，否则为上方和左方之和
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // 0. 检测
        if (obstacleGrid.empty())
        {
            return 0;
        }

        // 1. 构建DP数组
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<long>> dp(rows, vector<long>(cols, 0));

        // 1.1 初始化
        if(obstacleGrid[0][0] == 1){
            return 0;   // 表示出发点即为障碍
        }else
        {
            dp[0][0] = 1;
        }
        
        // 1.2 
        for (int i = 1; i < rows; i++)
        {
            dp[i][0] = (obstacleGrid[i][0]==0) && (dp[i-1][0]==1);
        }
        for (int i = 1; i < cols; i++)
        {
            dp[0][i] = (obstacleGrid[0][i]==0) && (dp[0][i-1]==1);
        }

        //  1.3 
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else
                {
                    dp[i][j] = 0;
                } 
            } 
        }

        return dp[rows-1][cols-1];
    }
};


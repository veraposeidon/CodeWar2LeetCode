/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
class Solution {
public:
    // 动态规划 记录正方形边长 dp[i][j] = min(dp[i-1][j]，dp[i][j-1]，dp[i-1][j-1]) + 1
    // 经典
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix.size(),n=matrix[0].size();
        int max_len = INT_MIN;
        vector<vector<int>> dp(m, vector<int>(n,0));    // dp表
        for(int i=0;i<m;i++){
            dp[i][0] = matrix[i][0] - '0';
            max_len = max(max_len, dp[i][0]);
        }
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i] - '0';
            max_len = max(max_len, dp[0][i]);
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]-'0' == 1){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        
        return max_len*max_len; // 返回面积
    }
};


/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> visit(n,vector<int>(m,0));
        visit[0][0] = 1;

        for (int i=1;i<m;i++){
            visit[0][i] = 1;
        }
        for (int j=1;j<n;j++){
            visit[j][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                visit[i][j] = visit[i-1][j] + visit[i][j-1];
            }
        }
        return visit[n-1][m-1];
    }
};


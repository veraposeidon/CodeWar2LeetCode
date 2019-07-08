/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
class Solution {
public:
    // 动态规划 原地动态规划即可
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        
        int m=triangle.size(),n=triangle[0].size();

        for(int i=m-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        
        return triangle[0][0];
    }
};


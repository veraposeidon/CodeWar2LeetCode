/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.37%)
 * Total Accepted:    228.1K
 * Total Submissions: 512.4K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 0. 边界判断
        if (numRows == 0) {
            return vector<vector<int>>(0);
        }
        

        // 1. 返回值
        vector<vector<int>> result;

        
        // 起始状态
        vector<int> layer1(1,1);
        result.push_back(layer1);

        // 动态过程
        for(int i = 1; i < numRows; i++)
        {
            vector<int> layer;
            for(int j = 0; j <=i; j++)
            {
                if (j == 0 || j == i) {
                    layer.push_back(1);
                }
                else
                {
                    layer.push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }
            result.push_back(layer);      
        }

        return result;
    }
};


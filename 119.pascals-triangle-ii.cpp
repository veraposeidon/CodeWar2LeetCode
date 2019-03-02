/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (41.87%)
 * Total Accepted:    185K
 * Total Submissions: 440.3K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
// 解法一：将构建杨辉三角形的路子拿来用，直接返回构建的最后一层。
class Solution1 {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        // 0. 边界判断
        if (numRows <= 0) {
            return vector<int>(0);
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

        return result[rowIndex];
    }
};



// 解法2：每次都在一个数组上拓展，累加就好了。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 0. 边界判断
        if (rowIndex < 0) {
            return vector<int>(0);
        }

        // 1. 构建初始vector
        vector<int> layer(0);

        // 2. 循环
        for(int i = 0; i <= rowIndex; i++)
        {
           // 第一步：扩展，数组长度加一
           layer.push_back(1);

           // 第二步：从头到尾累加
           for(int j = i-1; j >0; j--)
           {
               layer[j] = layer[j] + layer[j-1];
           }
        }
        // 3. 返回
        return layer;
        
    }
};









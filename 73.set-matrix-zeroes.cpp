/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (39.13%)
 * Total Accepted:    197.3K
 * Total Submissions: 502.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
// 解法一：O(mn)复杂度，拷贝一份，进行判断，出现零则在原矩阵上进行修改
// 时间复杂度O(mxn)
class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;

        vector<vector<int>> matrix_copy = matrix;    // 备份
        for(size_t i = 0; i < matrix_copy.size(); i++)
        {
            for(size_t j = 0; j < matrix_copy[0].size(); j++)
            {
                if( matrix_copy[i][j]  == 0 )
                {
                    for(size_t ii = 0; ii < matrix.size(); ii++)
                    {
                        matrix[ii][j] = 0;
                    }
                    for(size_t jj = 0; jj < matrix[0].size(); jj++)
                    {
                        matrix[i][jj] = 0;
                    }
                    
                }
            }
        }
    }
};

// 解法二：遍历原矩阵，用set记录零元素的横纵坐标
// 空间复杂度O(m+n) // 时间复杂度O(mxn)
// 虽然是空间复杂度降下来了，但是考虑到set的搜索，实际时间消耗上去了
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        set<int> rows,cols;
        // 遍历记录零元素的横纵坐标
        for(size_t i = 0; i < matrix.size(); i++)
        {
            for(size_t j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // 重新遍历矩阵
        for(size_t i = 0; i < matrix.size(); i++)
        {
            for(size_t j = 0; j < matrix[0].size(); j++)
            {
                if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end())
                {
                    matrix[i][j] =0;
                }
            }
        }
    }
};

// 高效方法：遍历数组时，遇见零则标记行头和列头为零。遍历完之后再去遍历首行和首列，遇到零则标记改行或改列
// 需要注意首行和首列的判断
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        
        bool isCol = false;
        for(size_t i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0) {
                 isCol = true;
             }
            for(size_t j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;   //标记该行
                    matrix[0][j] = 0;   //标记该列
                }
            }
        }
        for(size_t i = 1; i < matrix.size(); i++)
        {
            for(size_t j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 判断第一行
        if(matrix[0][0] == 0)
        {
            for(size_t i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i]=0;
            }   
        }
        if (isCol) {
            for (int i = 0; i <  matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }  
};
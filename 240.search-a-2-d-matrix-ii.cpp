/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.26%)
 * Total Accepted:    161.8K
 * Total Submissions: 401.9K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        int row=0,col=matrix[0].size()-1;
        {
            if(target == matrix[row][col]) return true;

            if(target > matrix[row][col]) row++;
            else col--;
        }
        return false;
    }
};


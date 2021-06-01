/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTracking(board, 0);
        return results;
    }

    void backTracking(vector<string> &board, int row) {
        // 终止条件
        if (row == board.size()) {
            results.push_back(board);
            return;
        }
        int currentCol = board[row].size();

        for (int col = 0; col < currentCol; col++)
        {
            // 排除不合法选项
            if (!isValidChoice(board, row, col)) continue;
            // in
            board[row][col] = 'Q';
            backTracking(board, row + 1);
            // out
            board[row][col] = '.';
        }
    }   

    bool isValidChoice(vector<string> &board, int row, int col) {
        int rows = board.size();
        // check conflict in same row.
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q') return false;
        }
        // check conflict in +45 angle.
        for (int i = row - 1, j = col + 1; i >= 0 && j < rows; i--, j++)
        {
            if (board[i][j] == 'Q') return false;
        }
        // check conflict in -45 angle.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
 };
// @lc code=end


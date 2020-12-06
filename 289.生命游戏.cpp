/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0 本挂又挂 1 本活又活 2 本活该挂 -1 本挂该活
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                int count = count_live(board, i, j);
                if (board[i][j] == 1)
                {
                    if (count < 2) {
                        board[i][j] = 2;
                    } else if (count <=3) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 2;
                    }
                } else {
                    if (count==3)
                    {
                        board[i][j] = -1;
                    }
                }
            }
        }
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                board[i][j] = (board[i][j] == 0 || board[i][j] == 2) ? 0 : 1; 
            }
        }
    }

    int count_live(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        if ((i-1)>=0 && (j-1)>=0) {
            count += board[i-1][j-1] <= 0 ? 0 : 1;
        }
        if ((i-1)>=0) {
            count += board[i-1][j] <= 0 ? 0 : 1;
        } 
        if ((i-1)>=0 && (j+1)<board[0].size()) {
            count += board[i-1][j+1] <= 0 ? 0 : 1;
        }
        if ((i+1)<board.size() && (j-1)>=0) {
            count += board[i+1][j-1] <= 0 ? 0 : 1;
        }
        if ((i+1)<board.size()) {
            count += board[i+1][j] <= 0 ? 0 : 1;
        }
        if ((i+1)<board.size() && (j+1)<board[0].size()) {
            count += board[i+1][j+1] <= 0 ? 0 : 1;
        }
        if ((j-1)>=0) {
            count += board[i][j-1] <= 0 ? 0 : 1;
        }
        if ((j+1)<board[0].size()) {
            count += board[i][j+1] <= 0 ? 0 : 1;
        }
        return count;
    }
};
// @lc code=end


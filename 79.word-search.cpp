/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }

        if(word.empty()){
            return true;
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(dfs_search(board, visited, i, j, word, 0)){
                    return true;
                }
            }  
        }

        return false;

    }

    bool dfs_search(vector<vector<char>>& board,vector<vector<bool>>& visited, int x, int y, string word, int pos){
        if(pos == word.size()){
            return true;
        }

        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()){
            return false;
        }

        if(visited[x][y]){
            return false;
        }

        if(board[x][y] != word[pos]){
            return false;
        }

        visited[x][y] = true;
        bool b = dfs_search(board, visited, x+1, y, word, pos+1) ||
                 dfs_search(board, visited, x-1, y, word, pos+1) ||
                 dfs_search(board, visited, x, y+1, word, pos+1) ||
                 dfs_search(board, visited, x, y-1, word, pos+1);
        visited[x][y] = false;
        
        return b;
    }
};


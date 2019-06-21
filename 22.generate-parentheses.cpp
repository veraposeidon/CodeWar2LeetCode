/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        dfs_gen(0,0,"",n);
        return result;
    }


    void dfs_gen(int left, int right, string &buffer, int n){
        if(left==n&&right==n){
            result.push_back(buffer);
            return;
        }

        if(left < n){
            dfs_gen(left+1, right, buffer+"(", n);
        }

        if(right<left){
            dfs_gen(left, right+1, buffer+")", n);
        }
        return;
    }
};


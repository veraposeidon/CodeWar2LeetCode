/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
// 进制换算的问题
class Solution {
public:
    string convertToTitle(int n) {
        int order = 26;
        string res = "";
        while (n>0)
        {
            char s = (n-1)%26 + 'A';
            n = (n-1) / 26;
            res = s + res;
        }
        return res;     
    }
};


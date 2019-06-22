/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
class Solution {
public:
    int titleToNumber(string s) {
        int order = 26;
        long res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            res = res * 26 + (c-'A'+1);
        }
        return res;
    }
};


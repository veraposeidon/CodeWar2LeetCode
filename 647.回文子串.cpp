/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        auto dp = vector< vector<bool> >(n, vector<bool>(n, false));
        for (int right = 0; right < n; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (left == right || right - left == 1 || dp[left+1][right-1])) {
                    dp[left][right] = true;
                    res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end


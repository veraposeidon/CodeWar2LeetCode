/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        auto dp = vector<bool>(size + 1, false);
        dp[0] = true;
        for (int i = 0; i <= size; i++) {
            if (!dp[i]) continue;
            for (string &item : wordDict) {
                int len = item.size();
                if (i + len > size) continue;
                // 确认是否相同
                dp[i + len] =  dp[i + len] || isSame(s, i, i - 1 + len, item) ; 
            }
        }
        return dp[size];
    }

    bool isSame(string &s, int startPos, int endPos, string &compare) {
        if (endPos >= s.size()) return false;
        
        for (int i = startPos, j = 0; i <= endPos; i++, j++) {
            if (s[i] != compare[j]) return false;
        }
        return true;
    }
};
// @lc code=end


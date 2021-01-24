/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        unordered_map<char, int> window;
        for (char ch : t) {
            target[ch] += 1;
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s.size())
        {
            char ch = s[right]; // 窗口新增字符
            right ++;

            if (target.count(ch))
            {
                window[ch] += 1;
                if (window[ch] == target[ch])
                {
                    valid += 1;
                }
            }

            // 收缩左边界
            while (valid == target.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];   // 窗口移除字符
                left ++;

                if (target.count(d))
                {
                    if (window[d] == target[d])
                    {
                        valid -= 1;
                    }
                    window[d] -= 1;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);   
    }
};
// @lc code=end


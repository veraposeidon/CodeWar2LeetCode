/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 0; i <= n; i++) {
            res[i] = countBit(i);
        }
        return res;
    }

    int countBit(int n) {
        int res = 0;
        while(n > 0) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};
// @lc code=end


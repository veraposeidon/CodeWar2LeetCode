/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mapAB;
        for(int a: A) {
            for (int b: B) {
                mapAB[a+b] += 1;
            }
        }
        int count = 0;
        for(int c: C) {
            for (int d: D) {
                if (mapAB.find(0-c-d) != mapAB.end()) {
                    count += mapAB[0-c-d];
                }
            }
        }

        return count;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int num : nums) {
            hashSet.insert(num);
        }

        int max_len = 0;

        for(int num : hashSet) {
            if (!hashSet.count(num-1))
            {
                int max_num = num;
                while (hashSet.count(max_num))
                {
                    max_num++;
                }
                max_len = max(max_len, max_num-num);
            }
        }
        return max_len;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
        {
            return 1;
        }
        
        vector<int> pos(nums.size()+21);
        for (int num : nums) {
            if (num <= 0) continue;
            if (num > nums.size()) continue;
            pos[num] += 1;
        }
        for (int i = 1; i < pos.size()+1; i++)
        {
            if (pos[i] == 0) return i;
        }
        return 1;       
    }
};
// @lc code=end


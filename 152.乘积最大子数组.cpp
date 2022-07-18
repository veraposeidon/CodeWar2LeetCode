/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxLast = nums[0];
        int minLast = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxF = max(maxLast * nums[i], max(nums[i], minLast * nums[i]));
            int minF = min(minLast * nums[i], min(nums[i], maxLast * nums[i]));
            ans = max(ans, maxF);
            maxLast = maxF;
            minLast = minF;
        }
        return ans;
    }
};
// @lc code=end


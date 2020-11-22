/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> leftMultiply(sz);
        vector<int> rightMultiply(sz);

        leftMultiply[0] = 1;
        rightMultiply[sz-1] = 1;
        for (size_t i = 1; i < sz; i++)
        {
            leftMultiply[i] = leftMultiply[i-1] * nums[i-1];
            rightMultiply[sz-1-i] = rightMultiply[sz-i] * nums[sz-i];
        }

        for (size_t i = 0; i < sz; i++)
        {
            leftMultiply[i] = leftMultiply[i] * rightMultiply[i];
        }
        
        return leftMultiply;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
// 迭代式动态规划
// 严重超时
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        // 检查
        if(nums.empty()) return true;

        // 
        vector<bool> visited(nums.size(), false);
        visited[0] = true;  // 天然访问第一个

        for (int i = 0; i < nums.size(); i++)
        {
            if(!visited[i]){
                return false;
            }

            for (int j = 1; j <= nums[i]; j++)
            {
                visited[i+j] = true;
            }
        }
        return true;
    }
};

// 动态规划
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        // 检查
        if(nums.empty()) return true;

        // 
        vector<int> dp(nums.size(), 0);
        dp[0] =  nums[0];  // 天然访问第一个

        for (int i = 1; i < nums.size(); i++)
        {
            if(dp[i-1] >= i){
                dp[i] = max(nums[i]+i, dp[i-1]);
            }else{
                dp[i] = 0;
            }
        }
        return dp[dp.size()-1]>=nums.size()-1;
    }
};

// 贪心算法，只用一个变量来保存最大的值
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 检查
        if(nums.empty()) return true;

        // 
        int max_step = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if(i > max_step) return false;

            max_step = max(nums[i]+i, max_step);
            if(max_step>=nums.size()-1) return true;
        }
        return max_step>=nums.size()-1;
    }
};

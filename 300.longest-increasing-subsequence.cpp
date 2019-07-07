/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;

        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int result = 0;
        for (int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }else{
                    dp[i] = max(dp[i], 1);
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};


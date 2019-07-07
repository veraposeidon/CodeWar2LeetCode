/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */
class Solution {
public:
    // 动态规划即可
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> LIS(nums.size(), 0);
        LIS[0] = 1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                LIS[i] = max(LIS[i], LIS[i-1]+1);
            }else{
                LIS[i] = 1;
            }
        }
        
        return *(max_element(LIS.begin(),LIS.end()));
    }
};

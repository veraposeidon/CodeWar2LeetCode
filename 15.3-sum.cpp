/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.59%)
 * Total Accepted:    508.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
// 解法一： 三重循环 O(n^3)
// 解法二：先对数组排序，然后开始遍历节点i，对i后的节点进行两端遍历（二分查找），得到三数相加为零即可，否则指针或加或减
// O(NLgN)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;

        // 0. 边界判断
        if (nums.size()<=2) {
            return vector<vector<int > >(0);
        }

        // 1. 排序
        sort(nums.begin(), nums.end());

        // 2. 遍历节点
        for(int i = 0; i < nums.size()-2; i++)
        {
            // 不能出现重复
            if(i ==0 || (i>0&&nums[i]!=nums[i-1])){
                int lo = i+1, hi = nums.size()-1, sum=0-nums[i];
                // 双指针找匹配对
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        result.push_back({nums[i], nums[lo], nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;  // 去重
                        while(lo < hi && nums[hi] == nums[lo-1]) hi--;  // 去重
                        lo++;hi--;
                    }else if(nums[lo]+nums[hi]>sum){
                        hi--;
                    }else{
                        lo++;
                    }
                }
            }
        }
        return result;
    }
};

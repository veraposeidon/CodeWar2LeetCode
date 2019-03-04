/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (50.67%)
 * Total Accepted:    302.5K
 * Total Submissions: 595.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */

// 解题一：从数组的角度 排序之后，一遍遍历
// 时间复杂度O(nlogn)
// 空间复杂度O(1)
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 0. 边界判断
        if (nums.size() == 0 || nums.empty()) {
            return false;
        }
        
        // 1. 排序
        sort(nums.begin(), nums.end());

        // 2. 线性遍历
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }

        return false;
    }
};


// 解法二：哈希表
// 时间复杂度O(n)
// 空间复杂度O(n)
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 0. 边界判断
        if (nums.size() == 0 || nums.empty()) {
            return false;
        }
        
        // 1. 排序
        // bool还降低空间呢
        unordered_map<int,bool> counts;

        // 2. 线性遍历
        for(auto num:nums)
        {
            if (counts.find(num) != counts.end()) {
                return true;
            }else
            {
                counts[num] = true;
            }
        }
        
        return false;
    }
};


// 解法三：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 0. 边界判断
        if (nums.size() == 0 || nums.empty()) {
            return false;
        }
        
        // 1. 排序
        // bool还降低空间呢
        unordered_map<int,bool> counts;

        // 2. 线性遍历
        for(auto num:nums)
        {
            if (counts.find(num) != counts.end()) {
                return true;
            }else
            {
                counts[num] = true;
            }
        }
        
        return false;
    }
};




/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.40%)
 * Total Accepted:    361.2K
 * Total Submissions: 893.1K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// 解决方案一：调用C++ STL 自带的lower_bound函数，他其实是用的二分查找方法
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto pos = lower_bound(nums.begin(), nums.end(), target);
        return pos - nums.begin();
    }
};

// 解决方案一：既然数组是排序的，那就使用二分查找法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 0. 边界条件
        if (nums.size() == 0 || nums.empty()) {
            return 0;
        }
        
        // 1. 二分查找
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int medium = (low+high) /2;
            // 找到则返回位置
            if(nums[medium] == target)
                return medium;  // 二分查找找到了
            // 目标大则抬高搜索空间
            else if (nums[medium] < target)
            {
                low = medium + 1;
            }
            else // 目标小则下沉搜索空间
            {
                high = medium - 1;
            } 
        }

        // 此处没找到,任选low或high进行处理
        if (nums[low] < target) {
            return low+1;
        }else
        {
            return low;
        }
    }
};


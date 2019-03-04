/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (59.01%)
 * Total Accepted:    418.5K
 * Total Submissions: 709.3K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 题目要求线性时间，则不应进行排序；
 * 题目要求不用额外空间，则不能建立哈希表等其他数据结构。
 * 唯一的解决方案是利用异或。相同的数异或为零。
 * 时间复杂度为O(n),空间复杂度为O(1);
 * 
 * 
 */
// 解决方案：位操作。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 0. 边界条件
        if (nums.empty()) {
            return 0;
        }
        // 1. 遍历进行异或
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            num ^= nums[i];
        }
        
    return num; 
    }
};


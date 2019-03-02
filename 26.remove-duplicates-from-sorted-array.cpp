/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.53%)
 * Total Accepted:    524.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */

#include <vector>
using namespace std;

// 解题思路：双指针
// 返回的是新的数组的长度，但是注意需要修改数组
// 由于数组已经排序好的，我们直接遍历数组，用指针A指向开始处，用指针B遍历数组，遇到A与B不同的，指针A步进并更新B所指数字，遇到A与B相同的，则A不动B动。
// 复杂度分析：时间复杂度：O(n),只需遍历一边数组
// 复杂度分析：空间复杂度：O(1),除了遍历用的指针没有别的了。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 0. 边界条件
        if(nums.size() == 0 || nums.empty())
            return 0;

        // 1. 遍历
        int i = 0; // 非重复指针，也表示数组长度
        for (int j = 1; j < nums.size() ; ++j) {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        // 2. 返回长度
        return i+1;
    }
};


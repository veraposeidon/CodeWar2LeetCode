/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (43.45%)
 * Total Accepted:    371.3K
 * Total Submissions: 853K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 * 
 * Your function should return length = 5, with the first five elements of nums
 * containing 0, 1, 3, 0, and 4.
 * 
 * Note that the order of those five elements can be arbitrary.
 * 
 * It doesn't matter what values are set beyond the returned length.
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
 * int len = removeElement(nums, val);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */

// in-place算法指的就是修改输入数据，无需额外空间，直接作为输出
// 注意题目中有一点：返回的数组，顺序是可以更改的。


#include <vector>
using namespace std;

// 解法1：双指针
// 时间复杂度：O(n),空间复杂度:O(1)。
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        // 0. 边界判断
        if(nums.size() ==0 || nums.empty())
            return 0;

        // 1. 开始遍历
        int i =0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};


// 解法2：双指针
// 考虑到两种情况，一种是前多个数都为不同，则有无意义的拷贝；一种是第一个数即相同，则后续每一步都需要移位。利用顺序可以改变的原则，则可以将相同的数字与数组末端交换
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 0. 边界判断
        if(nums.size() ==0 || nums.empty())
            return 0;

        // 1. 开始遍历
        int i =0;
        int len = nums.size();

        while (i < len)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[len-1];
                len--;
            } else  {
                i++;
            }
        }

        return i;
    }
};


/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// 思路：
// 1. 将左边的较小数与右边的较大数进行交换，保证当前排列变大，
// 2. 让较小数尽量靠右，较大数尽量小。
// 3. 交换完成后，较大数右边的部分进行升序排列，保证右部分是最小的。

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 2;
        
        while(left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }

        if (left >= 0) {
            int right = nums.size() - 1;
            while (right >= 0 && nums[left] >= nums[right]) {
                right--;
            }
            swap(nums[left], nums[right]);
        }
        
        reverse(nums.begin() + left + 1, nums.end());   
    }
};
// @lc code=end


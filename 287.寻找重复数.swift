/*
 * @lc app=leetcode.cn id=287 lang=swift
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        var slow = nums[0];
        var fast = nums[slow];
        while (fast < nums.count) && (nums[slow] != nums[fast])  {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (fast < nums.count) && (nums[slow] != nums[fast])  {
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
}
// @lc code=end


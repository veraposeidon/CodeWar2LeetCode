/*
 * @lc app=leetcode.cn id=31 lang=swift
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
    func nextPermutation(_ nums: inout [Int]) {
        var left: Int = nums.count - 2
        while left >= 0 && nums[left] >= nums[left + 1] {
            left -= 1
        }
        if left >= 0 {
            var right = nums.count - 1
            while right >= 0 && nums[left] >= nums[right] {
                right -= 1
            }
            // (nums[left], nums[right]) = (nums[right], nums[left])
            let tmp = nums[left]
            nums[left] = nums[right]
            nums[right] = tmp
        }
        var rightPart = Array(nums[(left+1)...]).reversed()
        nums.replaceSubrange((left+1)..., with: rightPart)   
    }
}
// @lc code=end


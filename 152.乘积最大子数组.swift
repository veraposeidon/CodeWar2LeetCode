/*
 * @lc app=leetcode.cn id=152 lang=swift
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        var maxLast = nums[0], minLast = nums[0], ans = nums[0]
        for i in 1..<nums.count {
            let maxNow = max(maxLast * nums[i], nums[i], minLast * nums[i])
            let minNow = min(minLast * nums[i], nums[i], maxLast * nums[i])
            ans = max(ans, maxNow)
            maxLast = maxNow
            minLast = minNow
        }
        return ans
    }
}
// @lc code=end


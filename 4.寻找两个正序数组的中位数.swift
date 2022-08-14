/*
 * @lc app=leetcode.cn id=4 lang=swift
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
    func findKthElement(_ nums1: [Int], _ nums2: [Int], _ kth: Int) -> Int {
        let len1 = nums1.count, len2 = nums2.count
        var offset1 = 0, offset2 = 0
        var kth = kth
        while true {
            if offset1 == len1 {
                return nums2[offset2 + kth - 1]
            }
            if offset2 == len2 {
                return nums1[offset1 + kth - 1]
            }
            if kth == 1 {
                return min(nums1[offset1], nums2[offset2])
            }
            
            let half = kth / 2
            let newOffset1 = min(offset1 + half, len1) - 1
            let newOffset2 = min(offset2 + half, len2) - 1
            let pivot1 = nums1[newOffset1], pivot2 = nums2[newOffset2]
            if pivot1 <= pivot2 {
                kth -= newOffset1 - offset1 + 1
                offset1 = newOffset1 + 1
            } else {
                kth -= newOffset2 - offset2 + 1
                offset2 = newOffset2 + 1
            }
        }
    }

    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let len1 = nums1.count, len2 = nums2.count
        let mid = (len1 + len2) / 2
        var res: Double = 0
        if (len1 + len2) % 2 == 1 {
            res = Double(findKthElement(nums1, nums2, mid + 1))
        } else {
            res = Double(findKthElement(nums1, nums2, mid) + findKthElement(nums1, nums2, mid + 1)) / 2.0
        }
        return res
    }
}
// @lc code=end


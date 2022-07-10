/*
 * @lc app=leetcode.cn id=448 lang=swift
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
    // func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
    //     var numsArray = Array(repeating: false, count: nums.count + 1)
    //     for num in nums {
    //         numsArray[num] = true
    //     }
    //     var result = [Int]()
    //     for i in 1..<numsArray.count {
    //         if numsArray[i] == false {
    //             result.append(i)
    //         }
    //     }
    //     return result
    // }
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        let size = nums.count
        var numsArray = nums
        for i in 0..<size {
            while (numsArray[i] != i + 1) && (numsArray[numsArray[i] - 1] != numsArray[i]) {
                numsArray.swapAt(i, numsArray[i] - 1)
            }
        }
        var result: [Int] = []
        for i in 0..<size {
            if numsArray[i] != i + 1 {
                result.append(i + 1)
            }
        }
        return result
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=11 lang=swift
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var i=0;
        var j=height.count-1;
        var max_res = 0;
        while i<j {
            let tmp = min(height[i], height[j]) * (j-i);
            if tmp>max_res {
                max_res = tmp;
            }
            if height[i]<height[j] {
                i+=1;
            }else {
                j-=1;
            }
        }
        return max_res;
    }
}
// @lc code=end


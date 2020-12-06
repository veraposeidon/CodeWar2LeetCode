/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_res = 0;
        while (i<j)
        {
            int tmp = min(height[i], height[j]) * (j-i);
            if (tmp > max_res)
            {
                max_res = tmp;
            }
            // 双指针法，容积由较小值和长度决定。考虑到移动较大值是不会增加容积，故移动较小值来减小问题边界
            if (height[i]<height[j])
            {
                i++;
            } else {
                j--;
            }
        }
        return max_res;
    }
};
// @lc code=end


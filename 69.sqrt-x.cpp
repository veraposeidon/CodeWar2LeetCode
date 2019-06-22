/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
// 用双指针法逼近不大于平方根值的整数
// 二分法逼近
class Solution {
public:
    int mySqrt(int x) {
        int left=0, right=x;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            long temp = (long)mid*(long)mid;
            if(temp > x) right = mid-1;
            else left = mid + 1;
        }
        return left - 1;
    }
};



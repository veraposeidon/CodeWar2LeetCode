/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.69%)
 * Total Accepted:    464.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 * 求最大连续和
 */

// 解法1：暴力解法
// 两轮循环，遍历i,j进行求和，找最大值
// 暴力法显然会引起超时
#include <numeric>
using namespace std;
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        // 0. 边界判断
        if(nums.size() == 0 || nums.empty())
            return 0;

        // 1. 遍历
        long long maxSum = nums[0];
        int maxI = 0;
        int maxJ = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // 注意accumate的形式是begin(),end().end()通常为数组长度，而不是数组长度-1。
            for(int j = i+1; j <= nums.size(); j++)
            {
                int sum = accumulate(nums.begin()+i, nums.begin()+j,0);
                if(sum > maxSum)
                {
                    maxI = i;
                    maxJ = j;
                    maxSum = sum;
                }
            }  
        }

        return maxSum;
    }
};

// 解法2： 分治法
// 用分治法的思想，把数组对半分为两个子数组，
// 接着数组的最大值可能在[left,mid]区间，[mid + 1,right]区间或者在横跨mid的区间内，只要取这三个区间的最大值即可。
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        // 0. 边界判断
        if(nums.size() == 0 || nums.empty())
            return 0;

        // 1. 调用分治法解决该问题
        int maxSum = findBigArray(nums, 0, nums.size() - 1);

        return maxSum;
    }

    int findBigArray(vector<int>& nums, int begin, int end)
    {
        // 结束条件
        if (begin == end)
            return nums[begin];

        int medium = (begin+end)/2;

        // 左半边最大值
        int left = findBigArray(nums, begin, medium);

        // 右半边最大值
        int right = findBigArray(nums, medium+1, end);

        // 跨越部分最大值
        int centerLeftBegin=medium;
        int centerLeftSum =0;
        int centerL = nums[medium];
        for(int i=medium; i>= begin;i--)
        {
            centerLeftSum += nums[i];
            if(centerLeftSum >= centerL)
            {
                centerL = centerLeftSum;
                centerLeftBegin = i;
            }
        }

        int centerRightEnd=medium+1;
        int centerRightSum = 0;
        int centerR = nums[medium+1];
        for(int i=medium+1; i<= end;i++)
        {
            centerRightSum += nums[i];
            if(centerRightSum > centerR)
            {
                centerR = centerRightSum;
                centerRightEnd = i;
            }
        }

        int center = centerL + centerR;
        
        // 三者取其大
        if (left >= center && left >= right)
		{
			return left;
		}
		else if (right >= left && right >= center)
		{
			return right;
		}
		else {
			return center;
		}

    }
};


// 解法三：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 0. 边界判断
        if(nums.size() == 0 || nums.empty())
            return 0;

        // 1. 创建数组用于保存sum
        vector<int> Sum(nums.size());
        Sum[0] = nums[0];
        int maxSum = Sum[0];

        // 2. 开始计算,计算前n个数的最大子序列和
        for(int i=1; i< nums.size();i++)
        {
            if(Sum[i-1] > 0)    // 前N个数的和大于零才有意义
            {
                Sum[i] = Sum[i-1] + nums[i];
            }
            else
            {
                Sum[i] = nums[i];
            }

            if(Sum[i] >= maxSum)
            {
                maxSum = Sum[i];
            }
        }

        return maxSum;
    }

};
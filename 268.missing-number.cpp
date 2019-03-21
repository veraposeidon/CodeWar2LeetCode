/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.71%)
 * Total Accepted:    253.7K
 * Total Submissions: 531.8K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// 解题思路：使用两个遍历，第一个遍历进行下标标注，并统计最大数，第二个遍历进行查找
// 因为不知道长度，利用vector扩容技术（错错错，知道nums的长度，再加一就好了。）
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> reg(nums.size()+1, 0);

        for (int i=0;i<nums.size();i++)
        {
            reg[nums[i]] = 1;
        }

        for (int i=0;i<reg.size();i++)
        {
            if ( reg[i] == 0 ) {
                return i;
            }
        }

        return 0;
    }
};

// 解题思路二：通过累加，判断最终差异
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int curSum = 0, resSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            resSum += i;
        }
        
        resSum += nums.size();
        return  resSum - curSum;

        
        
    }
};

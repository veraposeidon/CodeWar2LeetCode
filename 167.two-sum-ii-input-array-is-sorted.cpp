/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (49.16%)
 * Total Accepted:    212.7K
 * Total Submissions: 431.6K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */

// 解法一：既然是已经排序的，那就首尾两指针
// 时间复杂度就是O(n)了。
// 因为会有解。所以就不考虑特殊了。
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 0. 边界条件
        if(numbers.size() == 0 || numbers.size() == 1 || numbers.empty())
            return vector<int>(0);

        // 1. 首尾两指针遍历
        int index1 = 0, index2 = numbers.size()-1;
        while(index1 < index2){
            int sum = numbers[index1] + numbers[index2];
            if(sum < target)
                index1++;
            else if (sum > target)
            {
                index2--;
            }else
            {
                vector<int> result{index1+1, index2+1};
                return result;
            }
        }

        return vector<int>(0);
    }
};


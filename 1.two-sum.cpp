/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (40.24%)
 * Total Accepted:    1.4M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 *  1. 暴力解法（Brute Force）：双重遍历。
 *  复杂度分析：
 *      Time complexity : O(n^2)
 *      Space complexity: O(1). 
 *
 *  2. 两遍/一遍哈希表查找（Two-pass/One-Pass Hash Table）。
 *  拿空间换时间，使用哈希表建一个查找表：
 *  第一次循环时，不断建立每个元素的互补数字和对应下标；
 *  第二次循环时，根据当前元素和查找表进行查找。也可以一边建立查找表一边查找元素，有则返回。
 *
 *  复杂度分析：
 *      时间复杂度：O(n)
 *      空间复杂度：O(n)
 */

#include <vector>
#include <unordered_map>
#include <c++/algorithm>
#include <c++/sstream>
#include <c++/iostream>

using namespace std;


class Solution {
public:
    //查找表 方法
    std::vector<int> twoSum(vector<int> &nums, int target) {
        // 构建哈希表
        unordered_map<int, int> record;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()) //找到互补元素
            {
                result.push_back(record[complement]);
                result.push_back(i);
                break;
            }
            record[nums[i]] = i;    // 记录 当前值和对应下标
        }
        return result;
    }
};

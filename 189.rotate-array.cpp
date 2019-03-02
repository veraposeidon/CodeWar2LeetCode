/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (28.80%)
 * Total Accepted:    266.9K
 * Total Submissions: 922.8K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

// 解法一：暴力法
// vector弹出和压入
// 虽然方便，但还是很耗时的
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        // 0. 边界条件
        if (nums.size()==0 || nums.empty()) {
            return;
        }

        // 1. 遍历
        for(int i = 0; i < k; i++)
        {
            int end = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(), end);
        }        
    }
};

// 解法二：暴力法+去重
// vector弹出和压入
// 虽然方便，但还是很耗时的
// 通过取余减去不必要的动作
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        // 0. 边界条件
        if (nums.size()==0 || nums.empty()) {
            return;
        }

        //取余
        k = k % nums.size(); 

        // 1. 遍历
        for(int i = 0; i < k; i++)
        {
            int end = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(), end);
        }        
    }
};


// 解法三：拿空间换时间，做一个拷贝，从拷贝中获取需要的值
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 0. 边界条件
        if (nums.size()==0 || nums.empty() || k==0) {
            return;
        }

        // 1. 拷贝
        int N = nums.size();
        vector<int> numsCopy(nums.begin(), nums.end());

        // 2. 遍历并替换
        for(int i = 0; i < N; i++)
        {
            nums[(i+k)%N] = numsCopy[i];
        }
    }
};

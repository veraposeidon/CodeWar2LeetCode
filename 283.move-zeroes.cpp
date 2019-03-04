/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.61%)
 * Total Accepted:    423.6K
 * Total Submissions: 789.9K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// 解法一：vector的操作，删除和追加
// 关于remove和erase的做法
// std::vector<int>& vec = myNumbers; // use shorter name
// vec.erase(std::remove(vec.begin(), vec.end(), number_in), vec.end());
// 时间复杂度，O(n)，空间复杂度O(1)
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        // 0. 边界条件
        if(nums.empty())
            return;

        // 1. 适用 remove 函数，获取移除0后的数组追添位置
        auto iter = remove(nums.begin(),nums.end(),0);

        // 2. 利用迭代器替换为0
        for( ; iter!=nums.end(); iter++)
        {
            *iter = 0;
        }

        return;
    }
};



// 解法二：俗气的套路
// 时间复杂度O(n),空间复杂度O(n)
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        // 0. 边界条件
        if(nums.empty())
            return;

        // 1. 用copy的方式
        int zeroCount=0;
        vector<int> newCopy(0);
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) {
                zeroCount++;
            }else
            {
                newCopy.push_back(nums[i]);
            }
        }

        for(int i = 0; i < zeroCount; i++)
        {
            newCopy.push_back(0);
        }
        
        nums.assign(newCopy.begin(),newCopy.end());
    }
};


// 解法三：双指针
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 0. 边界条件
        if(nums.empty())
            return;

        int j=0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        
        for(; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }
};

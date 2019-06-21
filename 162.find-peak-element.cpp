/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
// 解法一：遍历即可(O(n)复杂度)
class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        // 0.
        if(nums.empty()){
            return -1;
        }

        // 
        int peakIndex = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[peakIndex]){
                return peakIndex;
            }else{
                peakIndex = i;
            }
        }
        
        return peakIndex;

    }
};

// 解法二：找到最大值，绝对满足条件，用分治法（二分法）
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 0.
        if(nums.empty()){
            return -1;
        }
        
        return divide_conquer(nums, 0 , nums.size()-1);
    }

    int divide_conquer(vector<int>& nums, int i, int j){
        if(i==j){
            return i;
        }

        int mid = i + (j-i)/2;
        int a = divide_conquer(nums, i, mid);
        int b = divide_conquer(nums, mid+1, j);
        return nums[a] >= nums[b] ? a:b;
    }
};


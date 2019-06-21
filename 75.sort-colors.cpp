/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 双指针
        int p1=0,p2=nums.size()-1;
        for (int i = 0; i <= p2; i++)
        {
            if(nums[i] == 0){
                swap(nums, i, p1++);
            }
            else if(nums[i]==2){
                swap(nums, i--, p2--);  // i--是因为跟2交换后还要判断他是否为0
            }
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};


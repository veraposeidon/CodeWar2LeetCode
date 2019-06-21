/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// logN 复杂度：二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // check
        if(nums.empty()) return -1;

        // 双指针
        int left=0,right=nums.size()-1;
        while (left<=right)
        {
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;
            
            int mid = left+ (right-left)/2;
            if(nums[mid] == target) return mid;
            
            // 判断是否为升序序列
            if (nums[left] <= nums[mid])
            {
                if(target<nums[mid]&&target>nums[left]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(target<nums[right]&&target>nums[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};


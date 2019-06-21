/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
// 双指针遍历O(n)复杂度
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return vector<int>{-1,-1};
        }

        int pos1=0,pos2=nums.size()-1;
        int index1 = -1,index2=-1;
        while((index1==-1||index2==-1)&&pos1<=pos2){
            if(nums[pos1]==target){
                index1 = pos1;
            }else{
                pos1++;
            }

            if(nums[pos2]==target){
                index2 = pos2;
            }else{
                pos2--;
            }
        }
        return vector<int>{index1,index2};
    }
};

// 因为是升序序列，因此用二分查找，找到两个第一次的指针即可
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return vector<int>{-1,-1};
        }

        int pos1=0,pos2=nums.size()-1;
        bool found1=false, found2=false;
        while(pos1<=pos2 && (!found1||!found2)){
            if(nums[pos1]==target && !found1){
                found1 = true;
            }
            if(nums[pos2]==target && !found2){
                found2 = true;
            }


            int mid = (pos1 + pos2)/2;
            if(nums[mid]>target){
                if(!found2){
                    pos2 = mid-1;
                }
            }else
            {
                if(!found1){
                    pos1 = mid+1;
                }
            }
        }
        return vector<int>{pos1,pos2};
    }
};


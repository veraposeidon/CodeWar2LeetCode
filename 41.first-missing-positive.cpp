/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.emptu()){
            return 1;
        }

        int i=0;
        while(i<nums.size()){
            if(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1]){
                int index = nums[i]-1;
                nums[i] = nums[index];
                nums[index] = index;
            }else{
                i++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]!=(i+1)){
                return i+1;
            }
        }
        
        return nums.size()+1;
    }
};


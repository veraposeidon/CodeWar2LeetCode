/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
// 解法一：
// 先排序，再数数(快排)
class Solution1 {
public:
    void quickSort(vector<int>&nums, int left, int right){
        int len = nums.size();
        if(left<right){
            int partitiion_index = partition(nums, left,right);
            quickSort(nums, left, partitiion_index-1);
            quickSort(nums, partitiion_index+1, right);
        }
    }   

    int partition(vector<int> &nums, int left, int right){
        int pivot = left;
        int index = pivot + 1;
        for (int i = index; i <= right; i++)
        {   
            if(nums[i] < nums[pivot]){
                swap(nums, index, i);
                index++;
            }
        }
        swap(nums, index-1, pivot);
        return index-1;
    }

    void swap(vector<int> &nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()){
            return -1;
        }

        quickSort(nums, 0, nums.size()-1);    // 升序排列
        return nums[nums.size()-k];
    }
};

// 解法2：用快排的思路来判断右侧的数目是不是K，是就是当前，不是就从左右两边区域选择哨兵
class Solution{
public:
    int partition(vector<int> &nums, int left, int right){
        int pivot = left;
        int index = pivot + 1;
        for (int i = index; i <= right; i++)
        {   
            if(nums[i] < nums[pivot]){
                swap(nums, index, i);
                index++;
            }
        }
        swap(nums, index-1, pivot);
        return index-1;
    }

    void swap(vector<int> &nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()){
            return -1;
        }

        int left=0,right=nums.size()-1;
        while (left<=right)
        {
            int partitiion_index = partition(nums, left, right);
            if(partitiion_index == nums.size()-k){
                return nums[partitiion_index];
            }else if(partitiion_index < nums.size()-k){
                left = partitiion_index + 1;
            }else{
                right = partitiion_index - 1;
            }
        }
        return -1;
    }
};


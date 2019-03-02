/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.75%)
 * Total Accepted:    329.3K
 * Total Submissions: 945.5K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */

// 解题思路一：两个序列是排好序的，那么暴力的方法就是第二个序列的每个元素在第一个序列上暴力搜索，在合适的位置把元素插入第一个序列中
// 双指针遍历搜索
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 0. 边界条件
        if (nums1.size() == 0 || nums1.empty() || nums2.size() == 0 || nums2.empty()) {
            return ;
        }

        // 1. 遍历搜索
        int pos1 = 0;
        int pos2 = 0;
        
        while((pos1 < m) && (pos2< n))
        {
            if (nums1[pos1] < nums2[pos2]) 
            {
                pos1++;
            }else{
                nums1.insert(nums1.begin() + pos1, nums2[pos2++]);
                pos1++;
                m++;
            }
        }

        // 判断nums2有无剩下的数
        // 清理nums1因插入扩增的长度
        if(pos2 < n)
        {
            nums1.erase(nums1.begin()+m,nums1.end());
            nums1.insert(nums1.end(), nums2.begin()+pos2, nums2.end());
        }
        else
        {
            nums1.erase(nums1.begin()+m,nums1.end());
        }
        
        

    }
};


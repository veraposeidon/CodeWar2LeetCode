/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (46.75%)
 * Total Accepted:    178.4K
 * Total Submissions: 381.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * 如果已经排序好了，我选择用双指针。
 * 
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * 双指针也同样适用啊。
 * 
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 在内存有限的情况下，且nums2存在硬盘上，那么如果只有nums2不能放在内存的话，
 * 将nums1映射成哈希表，然后读入一段nums2的数组，找出交集。
 * 如果nums1和nums2都很大，都不能完整放入内存的话，那么先分别利用外部排序将两个数组排序，然后每次从数组中读取两个数到内存记录交集。
 * 
 */

// 解法一： 排序之后，双指针遍历
// 效率不错
// 时间复杂度：O(nLogn)，空间复杂度：O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 0. 判空
        if (nums1.empty() || nums2.empty()) {
            return vector<int>(0);
        }
        
        // 1. 排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // 2. 双指针遍历
        vector<int> result(0);
        int pos1 = 0, len1 = nums1.size();
        int pos2 = 0, len2 = nums2.size();
        while(pos1 < len1 && pos2 < len2){
            if (nums1[pos1] == nums2[pos2]) {
                result.push_back(nums1[pos1]);
                pos1++;
                pos2++;
            }
            else if(nums1[pos1] < nums2[pos2]){
                pos1++;
            }else
            {
                pos2++;
            }
        }
        return result;
    }
};


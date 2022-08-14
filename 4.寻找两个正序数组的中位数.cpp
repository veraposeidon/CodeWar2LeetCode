/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if ((len1 + len2) % 2 == 0) {
            return (getKthElement(nums1, nums2, (len1 + len2) / 2) + getKthElement(nums1, nums2, (len1 + len2) / 2 + 1)) / 2.0;
        } else {
            return getKthElement(nums1, nums2, (len1 + len2) / 2 + 1);
        }
    }

    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        int offset1=0, offset2 = 0;
        
        while(true) {
            if (len1 == offset1) {
                return nums2[offset2 + k - 1];
            }
            if (len2 == offset2) {
                return nums1[offset1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[offset1], nums2[offset2]);
            }

            int half = k / 2;
            int newOffset1 = min(offset1 + half, len1) - 1;
            int newOffset2 = min(offset2 + half, len2) - 1;
            int val1 = nums1[newOffset1];
            int val2 = nums2[newOffset2];
            if (val1 <= val2) {
                k -= (newOffset1 - offset1 + 1);
                offset1 = newOffset1 + 1;
            } else {
                k -= (newOffset2 - offset2 + 1);
                offset2 = newOffset2 + 1;
            }
        }
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     auto numarr = vector<bool>(nums.size() + 1, false);
    //     for (auto num : nums) {
    //         numarr[num] = true;
    //     }
    //     vector<int> res;
    //     for (int i = 1; i < numarr.size(); i++) {
    //         if (!numarr[i]) {
    //             res.push_back(i);
    //         }
    //     }
    //     return res;
    // }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            while ((nums[i] != i + 1) && (nums[nums[i] - 1] != nums[i])) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> res;
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end


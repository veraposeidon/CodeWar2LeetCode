/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 环形链表找入口, 快慢指针
        int slow = nums[0];
        int fast = nums[nums[0]];
        while ( fast<nums.size() && nums[slow] != nums[fast])
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while (fast<nums.size() && nums[slow] != nums[fast])
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return nums[slow];
    }
};
// @lc code=end


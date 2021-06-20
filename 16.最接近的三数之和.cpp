/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for (int a = 0; a < n; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }

            int b = a + 1, c =  n - 1;
            while (b < c) {
                int sum = nums[a] + nums[b] + nums[c];
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) {
                    int c0 = c - 1;
                    while (b < c0 && nums[c0] == nums[c]) {
                        c0--;
                    }
                    c = c0;
                } else {
                    int b0 = b + 1;
                    while (b0 < c && nums[b0] == nums[b]) {
                        b0++;
                    }
                    b = b0;
                }
            }
        }
        return best;
    }
};
// @lc code=end


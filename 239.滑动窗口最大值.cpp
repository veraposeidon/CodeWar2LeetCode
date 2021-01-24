/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 利用优先队列
        int N = nums.size();
        priority_queue<pair<int, int>> queue;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            queue.push(make_pair(nums[i], i));
        }
        res.push_back(queue.top().first);
        for (int i = k; i < N; i++)
        {
            queue.push(make_pair(nums[i], i));
            while (queue.top().second <= i-k)
            {
                queue.pop();    // 保证队列最大值在窗口内
            }
            res.push_back(queue.top().first);
        }
        return res;
    }
};
// @lc code=end


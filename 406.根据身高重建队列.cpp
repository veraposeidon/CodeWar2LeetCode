/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [ ]( const auto& lhs, const auto& rhs ) {
            if (lhs[0] > rhs[0]) {
                return true;
            } else if (lhs[0] < rhs[0]) {
                return false;
            } else {
                return lhs[1] < rhs[1];
            }
        });
        vector<vector<int>> result;
        for (auto &person : people) {
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& candidates, int startPos, int target, vector<int> &cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = startPos; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                cur.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i], cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        dfs(candidates, 0, target, res);
        return ans;
    }
};
// @lc code=end


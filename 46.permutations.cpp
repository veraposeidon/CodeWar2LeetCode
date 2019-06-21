/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return vector<vector<int>>();
        }

        vector<bool> visited(nums.size(), false);
        vector<int> gen;
        dfs_gen(nums, visited, 0, gen);

        return result;
    }

    void dfs_gen(vector<int>& nums, vector<bool>& visited, int n, vector<int> &gen){
        if(n == nums.size()){
            result.push_back(gen);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(!visited[i]){
                visited[i] = true;
                gen.push_back(nums[i]);
                dfs_gen(nums, visited, n+1, gen);
                // 注意为了下一个方案，需要吐出当前的额
                gen.pop_back();
                visited[i] = false;
            }

        }
        
        return;
    }
};


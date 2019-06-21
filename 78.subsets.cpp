/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
// 两种解法
// 第一种方式：迭代式，从头开始，第i位加上它表示有他的状态，不然就是没他的状态
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 0. check
        if(nums.empty()){
            return vector<vector<int>>();
        }
        
        // 1.
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        // 2.
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int size = result.size();
            for (int j = 0; j < size; j++)
            {
                temp = result[j];
                temp.push_back(num);
                result.push_back(temp);
            }
        }
        return result;
    }
};

// dfs
class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // 0. check
        if(nums.empty()){
            return vector<vector<int>>();
        }
    
        vector<int> temp;
        dfs_search(nums, 0, temp);

        return result;
    }

    void dfs_search(vector<int>& nums, int pos, vector<int> &out){
        if(pos==nums.size()){
            result.push_back(out);
            return;
        }
        
        dfs_search(nums, pos+1, out);
        
        out.push_back(nums[pos]);
        dfs_search(nums, pos+1, out);
        out.pop_back();
        
        return;
    }
};



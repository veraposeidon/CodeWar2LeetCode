/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// 思路一：
// 哈希表 + 排序
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // check
        if(nums.empty()){
            return vector<int>();
        }

        // hash map 
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] += 1;
        }

        // sort
        vector<pair<int, int>> elems(map.begin(), map.end());
        sort(elems.begin(), elems.end(), [=](pair<int, int> a, pair<int,int> b){return a.second>b.second;});

        // 
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(elems[i].first);
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // check
        if(nums.empty()){
            return vector<int>();
        }

        // hash map 
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] += 1;
        }

        // sort
        priority_queue<pair<int,int>> que;
        for (auto iter : map)
        {
            que.push({iter.second, iter.first});
        }

        // result 
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(que.top().second);
            que.pop();
        }
        
        return result;
    }
};



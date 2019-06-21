/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // check
        if(intervals.empty()){
            return {};
        }

        // sort
        sort(intervals.begin(), intervals.end(),
                [=](vector<int>a, vector<int>b){ return a[0] < b[0];});

        // iterate
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (const auto& interval : intervals)
        {
            // new interval
            if(interval[0]>result.back()[1]){
                result.push_back(interval);
            }else{
                result.back()[1] = max(interval[1], result.back()[1]);
            }
        }
        return result;
    }
};


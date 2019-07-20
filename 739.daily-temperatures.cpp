/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
class Solution {
public:
    struct temp_day{
        int temp;
        int index;
        temp_day():temp(0),index(0){}
        temp_day(int tmp, int dy):temp(tmp),index(dy){}
    };
    // 维护一个递减栈
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty()) return {};
        int len = T.size();
        vector<int> result(len, 0);
        stack<temp_day> stk;
        
        stk.push(temp_day(T[0],0));
        
        for(int i=1;i<len;++i){
            while(!stk.empty() && stk.top().temp < T[i]){
                result[stk.top().index] = i - stk.top().index;
                stk.pop();
            }
            stk.push(temp_day(T[i],i));
        }
        return result;
    }
};


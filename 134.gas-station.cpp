/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 0. check
        if(gas.empty() || cost.empty()){
            return -1;
        }
        if(gas.size() != cost.size()){
            return -1;
        }

        // 1. two loop
        int answer = -1;
        for(int i=0;i<gas.size();i++){
            // start i
            int remain=gas[i];
            for(int j=1;j<=gas.size();j++){
                // station
                int gas_station = (i+j)%gas.size();
                int cost_station = (i+j-1)%gas.size();
                remain = remain - cost[cost_station];
                if(remain < 0){
                    break;
                }
                remain += gas[gas_station];
            }
            if(remain >= 0){
                answer = i;
                break;
            }
        }
        return answer;
    }
};


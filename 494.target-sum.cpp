/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
class Solution {
public:
    // DFS
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, 0, S);
        return count;
    }
    
    void dfs(vector<int>& nums, int pos, int sum, int S){
        // 终止条件
        if(pos==nums.size()){
            if(sum==S){
                count += 1;
                return;
            }else{
                return;
            }
        }
        
        // // 加优化条件，即全加或全减到不了目标，就直接返回即可
        // auto remainSum = accumulate(nums.begin()+pos, nums.end(),0);
        // if(sum + remainSum < S) return;
        // if(sum - remainSum > S) return;
        
        // 递归
        auto back = sum;
        sum += nums[pos];
        dfs(nums, pos+1, sum, S);
        sum = back;
        sum -= nums[pos];
        dfs(nums, pos+1, sum, S);
        
        return;
    }
    
private:
    int count=0;
};


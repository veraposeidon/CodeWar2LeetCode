/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
class Solution {
public:
    // 动态规划
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return false;
        vector<int> counts(amount+1, amount+1); // 凑齐i元最少需要的硬币数
        counts[0] = 0;  
        for(int i=1;i<=amount;i++){
            for(int coin : coins){
                if(i-coin==0){
                    counts[i] = 1; 
                }
                else if(i-coin>0){
                    counts[i] = min(counts[i], counts[i-coin]+1);
                } 
            }
        }    
        return counts[amount]>amount?-1:counts[amount];
    }
};

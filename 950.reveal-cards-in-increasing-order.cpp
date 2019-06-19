/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 解法一：反向规则输入
        // 0. check
        if(deck.empty()){
            return vector<int>();
        }
        
        // 1. 排序 
        sort(deck.begin(), deck.end());
        // 2. 
        vector<int> result;
        for(int i= deck.size()-1;i >= 0;i--){
            // 右移
            if(!result.empty()){
                rotate(result.begin(), result.begin()+result.size()-1, result.end());
            }
            // 插入
            result.insert(result.begin(), deck[i]);
        }
        return result;
    }
};


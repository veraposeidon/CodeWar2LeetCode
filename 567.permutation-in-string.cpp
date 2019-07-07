/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
class Solution {
public:
    // 哈希表做统计
    // 审题不清
    // 看来还是要用滑窗法啊
    bool checkInclusion(string s1, string s2) {
        // check
        if(s1.empty())  return true;
        if(s2.empty())  return false;
        if(s2.size() <s1.size()) return false;
        vector<int> res1(26, 0);
        vector<int> res2(26, 0);
        
        // s1的统计
        for(int i=0;i<s1.size();i++){
            res1[s1[i]-'a'] ++;
            res2[s2[i]-'a'] ++;
        }
        
        if(res1 == res2) return true;
        
        // 设置窗口
        for (int i=0;i<s2.size()-s1.size();i++){
            res2[s2[i] - 'a'] --;
            res2[s2[i+s1.size()] - 'a'] ++;
            if(res1 == res2) return true;
        }
        
        return false;
    }
};


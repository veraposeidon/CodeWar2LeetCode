/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
class Solution {
public:
    // 解法一：暴力解法
    string reverseWords(string s) {
        // check
        if(s.empty()) return s;
        
        vector<string> strs;
        string temp="";
        for(char ch:s){
            if(ch != ' ') temp += ch;
            else {
                if(!temp.empty()) strs.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty())   strs.push_back(temp);
        
        string res="";
        for(int i=strs.size()-1;i>=0;i--){
            res += strs[i] + " ";
        }
        
        // 删除最后一个字符
        res.erase(res.end()-1);
        return res;   
    }
};


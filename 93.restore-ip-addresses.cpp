/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
class Solution {
public:
    // DFS深度优先遍历
    // 最大255和不能以0开头
    
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 4*4 || s.size() < 4) return {};
        dfs(s, "", 0);
        return res;
    }
    
    // 判断该区间是否有效
    bool validNum(string str){
        int num = stoi(str);
        return num<=255 && str==to_string(num);
    }
    
    void dfs(string s, string result, int count){
        if(count == 4 && s.empty()){
            result.erase(result.end()-1, result.end());
            res.push_back(result);
            return;
        }
        
        for(int i=1;i<=3;i++){
            if(i>s.size()) continue;
            string sub = s.substr(0, i);
            if(validNum(sub)){
                result += sub + ".";
                dfs(s.substr(i), result, count+1);
                result.erase(result.end()-i-1, result.end());
            }    
        }
    }
    
    
};


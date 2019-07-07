/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
class Solution {
public:
    // 用栈的方式解决
    // c++ string 不提供split,自己实现
    void process_temp(stack<string> &stck_pth, string &temp){
        if(temp.empty()){
            return;
        } 
        if(temp == "."){
            temp = "";
            return;
        } 
        if(temp == ".."){
            temp = "";
            if(!stck_pth.empty()) stck_pth.pop();
        }else{
            stck_pth.push(temp);
            temp = "";
        }
    }
    
    string simplifyPath(string path) {
        // check
        if(path.empty()) return path;
        
        stack<string> stck_pth;
        string temp;
        for(char ch : path){
            if(ch=='/'){
                process_temp(stck_pth, temp);
            }else{
                temp += ch;
            }
        }
        process_temp(stck_pth, temp);
        
        // 反向构造
        string res;
        if(stck_pth.empty()) return "/";
        while(!stck_pth.empty()){
            res = "/" + stck_pth.top() + res;
            stck_pth.pop();
        }
        return res;
    }
};


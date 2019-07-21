/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
class Solution {
public:
    // stack
    // 一个stack用于保存数字，一个stack用于保存字符串
    string decodeString(string s) {
        stack<string> stk_str;
        stack<int> stk_num;
        
        int cnt=0;
        string str="";
        
        for(auto ch:s){
            if(isdigit(ch)){
                cnt = 10*cnt+ch-'0';
            }else if(ch=='['){
                stk_num.push(cnt);
                stk_str.push(str);
                cnt=0;str.clear();
            }else if(ch==']'){
                int num=stk_num.top();stk_num.pop();
                for(int i=0;i<num;i++){
                    stk_str.top() += str;
                }
                str=stk_str.top();
                stk_str.pop();
                
            }else{
                str+=ch;
            }
        }
        
        return stk_str.empty()?str:stk_str.top();
    }
};


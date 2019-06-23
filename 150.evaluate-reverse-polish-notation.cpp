/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
// 用栈来解决
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return -1;
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++)
        {
            string str = tokens[i];
            if(isManuplate(str)){
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(calc(first, second, str));
            }else{
                nums.push(stoi(str));
            }
        }
        return nums.top();
    }
    bool isManuplate(string str){
        return str=="+"||str=="-"||str=="*"||str=="/";
    }

    int calc(int first, int second, string sign){
        if(sign == "+"){
            return first+second;
        }

        if(sign == "-"){
            return first-second;
        }

        if(sign == "*"){
            return first*second;
        }

        if(sign == "/"){
            return first/second;
        }
        return -1;
    }
};


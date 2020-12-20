/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int pos = 0;
        int num = 0;
        char lastOp = '+';
        while (pos<s.size())
        {
            char ch = s[pos];
            if (isdigit(ch))
            {
                num = num * 10 + (ch-'0');
            } 
            if ((!isdigit(ch) && ch!=' ')|| (pos >= s.size()-1))
            {
                if (lastOp == '+')
                {
                    stk.push(num);
                } else if (lastOp == '-')
                {
                    stk.push(-num);
                } else if (lastOp == '*')
                {
                    int pre = stk.top();
                    stk.pop();
                    stk.push(num*pre);
                } else if (lastOp == '/')
                {
                    int pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                }
                num = 0;
                lastOp = ch;
            }    

            pos++;
        }
        while (!stk.empty())
        {
           num += stk.top();
           stk.pop();
        }
        
        return num;
    }
};
// @lc code=end


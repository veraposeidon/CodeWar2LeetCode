/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.05%)
 * Total Accepted:    536.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// 解题思路：很明显的用堆栈来完成 
// 不同压入，相同弹出
class Solution {
public:

    char pair(char c)
    {
        if (c==')') {
            return '(';
        }
        if (c==']') {
            return '[';
        }
        if (c=='}') {
            return '{';
        }
        
        return '0';

    }

    bool isValid(string s) {
        if (s.empty())
            return true;

        stack<char> store;

        for ( int i=0;i<s.size();i++ )
        {
            char c = s[i];

            if (store.empty()) {
                store.push(c);
                continue;
            }
            

            if (store.top() == pair(c)) {
                store.pop();         
            }else
            {
                store.push(c);

                // 该操作直接加速
                if (c==']' || c=='}' || c==')')
                    return false;
            }
        }

        if ( store.empty() ) {
            return true;
        }

        return false;
                
    }
};


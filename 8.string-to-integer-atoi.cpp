/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.50%)
 * Total Accepted:    329.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */

// 解法一：按照规则设定即可
// 寻找字符串特定位置可以使用fisrt_not_of
class Solution {
public:
    int myAtoi(string str) {
        // 0. 判空
        if (str.empty()) {
            return 0;
        }
        
        // 1. while
        int num = 0,sign=1;
        size_t i=0,N = str.size() ;
        
        // 找到非第一个非空格字符
        // 特殊情况全为空格
        i = str.find_first_not_of(" ");
        if (i == string::npos) {
            return 0;
        }

        // 判断为负号还是数字
        if(str[i]=='-')
            sign = -1;
        else if (str[i]=='+')
        {
            sign = 1;
        }else if (isdigit(str[i])) {
            sign = 1;
            num = str[i] - '0';
        }else
        {
            return 0;
        }
        
        // 开始
        i++;

        // 开始计数
        while(isdigit(str[i]) && i < N){
            int pos = str[i]-'0';

             // 判断溢出
             if (sign==1 && (num>(INT_MAX/10) || (num==(INT_MAX/10) && pos >= INT_MAX % 10))) {
                 return INT_MAX;
             }
             
             if (sign==-1 && (num>(INT_MAX/10) || (num==(INT_MAX/10) && pos >= (INT_MIN % 10 * -1)))) {
                 return INT_MIN;
             }
             
             num = num * 10 + pos;

             i++;
            
        }
        
        return num*sign;
    }
};


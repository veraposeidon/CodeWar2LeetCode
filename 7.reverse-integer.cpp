#include <c++/climits>

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.09%)
 * Total Accepted:    605.2K
 * Total Submissions: 2.4M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 也就是说，肯定不能直接输出，因为需要判断输出的值是否溢出。这道题就是要判断溢出问题。
 */
class Solution {
public:
    int reverse(int x) {

        // inverse the number
        int inversN = 0;

        while(x!=0)
        {
            // 最后一位
            int pop = x % 10;
            x = x / 10;

            // 判断条件
            if(inversN > INT_MAX/10 || (inversN==INT_MAX/10 && pop>7))
                return 0;
            if(inversN < INT_MIN/10 || (inversN==INT_MIN/10 && pop>8))
                return 0;

            inversN = inversN*10 + pop;
        }

        return inversN;
    }
};

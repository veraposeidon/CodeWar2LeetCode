/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.25%)
 * Total Accepted:    388K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// 解法一：暴力匹配（直接用C++的find函数）
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 0. 边界判断
        if( haystack.empty() && needle.empty() )
            return 0;   //  下标为零
        
        if( haystack.empty() )
            return -1; // 不会搜索到needle

        if ( needle.empty() )
            return 0; // 按照题意，返回零

        std::size_t found = haystack.find(needle);
        if (found != std::string::npos) {
            return found;
        }

        return -1;
    }
};


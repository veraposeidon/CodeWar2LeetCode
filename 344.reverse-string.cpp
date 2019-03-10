/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (62.76%)
 * Total Accepted:    377.3K
 * Total Submissions: 601.2K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 
 */

// 解法一：直接调用reverse函数
class Solution1 {
public:
    void reverseString(vector<char>& s) {
        // 0. 边界条件
        if (s.empty()) {
            return ;
        }

        // 1. 
        reverse(s.begin(), s.end());

        // 2.
        return ;
        
    }
};



// 解法2：自己实现reverse机制
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 0. 边界条件
        if (s.empty()) {
            return ;
        }

        // 1. 
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return;    
    }
};


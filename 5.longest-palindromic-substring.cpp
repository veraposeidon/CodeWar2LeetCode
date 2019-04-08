/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.79%)
 * Total Accepted:    515K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
// 解法零：最长公共子串不可以。奇数可以偶数不可以。
// 解法一：暴力解法 双指针找子串，再通过遍历判断是否为回文串，并记录最长的。这样的时间复杂度为O(n^3),空间复杂度为O(1)。
// 解法二：将问题分解为子问题P(i,j) = ( P(i+1, j-1) and si==sj ) 这种问题主要是拆解成小问题再配合DP表
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        if(s.size() == 1)
            return s;
        // DP 表
        vector<vector<bool>> dp_table(s.size(), vector<bool>(s.size(), false));
        // 初始化DP表（一位回文或者两位回文）
        for (size_t i = 0, j = i + 1; i < s.size(), j < s.size(); i++, j++) {
            dp_table[i][i] = true;
            dp_table[i][j] = s[i] == s[j];
        }

        // 动态解决子问题
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i + 2; j < s.size(); j++) {
                dp_table[i][j] = dp_table[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        // 一行内true最广的边界
        vector<string> results;
        for (int i = 0; i < s.size(); i++) {
            vector<int> index(0);  // true下标
            for (int j = i; j < s.size(); j++) {
                if (dp_table[i][j])
                    index.push_back(j);
            }
            if (index.size() < 1) {
                continue;
            }
            int first = index[0];
            int last = index.back();
            string result;
            result.assign(s.begin() + first, s.begin() + last + 1);
            results.push_back(result);
        }


        int max = 0;
        string maxString = "";
        for (auto str : results) {
            if (str.size() > max) {
                max = str.size();
                maxString = str;
            }
        }
        return maxString;
    }
};

// int main(){
//     Solution s;
//     s.longestPalindrome("cbbd");

//     return 0;
// }


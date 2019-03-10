/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.22%)
 * Total Accepted:    323.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
// 解法一：双指针
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        int i=0,j=s.size()-1;
        while(i<j){
            while((!isalnum(s[i])) && i<j)
                i++;
            
            while((!isalnum(s[j])) && i<j)
                j--;
            

            if(toupper(s[i])!=toupper(s[j]))
                return false;

            i++;
            j--;
        }
        
        return true;
    }
};


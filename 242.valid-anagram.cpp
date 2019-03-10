/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (50.93%)
 * Total Accepted:    303.5K
 * Total Submissions: 595.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// 解决思路一：构建哈希表，再逐一匹配。
// 稍显复杂，时间复杂度认为O(n)，空间复杂度为O(n)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        // 0. 边界条件
        if(s.empty() && t.empty())
            return true;
        if (s.empty() || t.empty() || (s.size()!=t.size())) {
            return false;
        }
        
        // 1. 构建两个哈希表
        unordered_map<char, int> hashS;
        unordered_map<char, int> hashT;
        for(int i = 0; i < s.size(); i++)
        {
            if(hashS.find(s[i])!= hashS.end())
                hashS[s[i]]+=1;
            else
                hashS[s[i]] =1;

            if(hashT.find(t[i])!= hashT.end())
                hashT[t[i]]+=1;
            else
                hashT[t[i]] =1;
        }

        // 2. 比较两个哈希表
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (hashT.find(c)!=hashT.end()) {
                if(hashT[c]!=hashS[c])
                    return false;
            } 
            else
            {
                return false;
            }
        }

        return true;
        
    }
};

// 解法二：排序
// 排序之后直接比较字符串大小即可
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        // 0. 边界条件
        if(s.empty() && t.empty())
            return true;
        if (s.empty() || t.empty() || (s.size()!=t.size()))
            return false;

        // 1. 排序
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // 2. 比较
        return s==t;
    }
};

// 解法三：因为是字符串，所以可以定长，用数组来表示
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 0. 边界条件
        if (s.size() != t.size())
            return false;

        // 1. 定义数组
        int chars[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            chars[s[i]-'a']++;  // 统计加一
            chars[t[i]-'a']--;  // 统计减一
        }
        for(int i = 0; i < 26; i++) //注意此处遍历的是数组，不是字符串。
        {
            if (chars[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};

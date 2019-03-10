/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.17%)
 * Total Accepted:    231.9K
 * Total Submissions: 471.5K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

// 解法一：暴力搜索
// O(n^2)就能解决了,空间复杂度O(1)
class Solution1 {
public:

    int firstUniqChar(string s) {
        // 0. 边界条件
        if(s.empty())
            return -1;
         if(s.size()==1)
            return 0;
        // 1. 双重遍历
        for(int i = 0; i < s.size(); i++)
        {
            bool dual = false;
            for(int j = 0; j < s.size(); j++)
            {
                if(i==j)
                    continue;
                if(s[j] == s[i])
                {
                    dual = true;
                    break;
                }
            }
            
            if(!dual)
                return i;
        }
        
        // 
        return -1;
    }
};

// 解法二：哈希表
// 哈希表虽然无序，但是可以先构建哈希表，在遍历一遍
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:

    int firstUniqChar(string s) {
        // 0. 边界条件
        if(s.empty())
            return -1;

        // 1. 构建哈希表
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (hash.find(c) != hash.end()) {
                hash[c]+=1;
            }else
            {
                hash[c]=1;
            }
        }

        // 2. 遍历找第一个独立元素
        for(int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1) {
                return i;
            }
        }
        
        // 3. 无即返回-1
        return -1;

    }
};


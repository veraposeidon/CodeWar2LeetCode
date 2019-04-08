/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.07%)
 * Total Accepted:    856.6K
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
// 解法一：暴力搜索
// 用双指针for循环，并且用set进行有重复字符的判断(用set虽好，其实用数组标记应该更快)
// 时间复杂度O(n^3)，双重循环为n^2, 还需要再来一次搜索需要n
// TLE
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int n = s.size();
        int ans = 0;
        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = i+1; j <= n; j++)
            {
                // 判断字符串是否有重复
                if(allUnique(s, i, j))
                    ans = max(ans, int(j-i));
            }
        }
        return ans;
    }

    // 判断该区间是否有重复字符
    bool allUnique(string s, int i_, int j_){
        set<char> hash_set;
        for(size_t i = i_; i < j_; i++)
        {
            char ch = s[i];
            if(hash_set.find(ch) != hash_set.end())
                return false;
            hash_set.insert(ch);
        }
        return true;
    }
};

// 滑窗法：基于暴力解法的优化
// 维护一个set, 根据窗口的变化来变动
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int n=s.size();
        set<char> hash_set;
        int ans=0, i=0, j=0;
        while(i<n &&j<n){
            if(hash_set.find(s[j]) == hash_set.end())
            {
                hash_set.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }else{
                hash_set.erase(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};


// 继续优化
// 不要遇到重复只跳一个，可以记录下标，然后直接跳到新的不重复的地方
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int n=s.size();
        int ans = 0;
        unordered_map<char, int> char_map;
        for(int j = 0, i=0; j < n ; j++)
        {
            // 之前出现过，先找到下标
            if(char_map.find(s[j]) != char_map.end())
            {
                i = max(char_map[s[j]], i);
            }
            ans = max(ans, j-i+1);
            char_map[s[j]] = j+1;
        }
        return ans;
    }
};
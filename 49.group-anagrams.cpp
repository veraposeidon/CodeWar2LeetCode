/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (45.22%)
 * Total Accepted:    311.8K
 * Total Submissions: 684.8K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
// 如果字符各不相同，则可以对字符串的字符进行排序即可
// 如果字符出现重复，则应该进行计数即可。 为了保险，进行计数统计最好
// 用计数则用hash表即可
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > count_map;
        // 统计，索引为每个字符串的升序排布
        for(string str : strs)
        {
            string local_str = str;
            sort(local_str.begin(), local_str.end());
            count_map[local_str].push_back(str);
        }
        // 整理输出
        vector<vector<string> > result;
        for(auto k: count_map)
        {
            result.push_back(k.second);
        }

        // 返回结果
        return result;
    }
};


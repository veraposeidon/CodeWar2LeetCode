
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.95%)
 * Total Accepted:    407.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <string>
#include <vector>

using namespace std;

// 解法1：暴力解法（属于共同子串的简化版本）其实是属于（垂直扫描）
// 遍历所有的str,从头开始记，一旦遇到不同的，则停止
// 复杂度分析：时间复杂度 O(S)，S表示所有字符串的字符总个数
// 复杂度分析：空间复杂度 O(1), 只用了一个字符串来记录
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 0. 边界判断
        if(strs.size() == 0)
            return "";

        // 1. 找最短字符串长度
        int lenMin = UINT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            if (lenMin > strs[i].size()){
                lenMin = strs[i].size();
            }
        }

        string comm = "";
        // 2. 开始遍历
        for (int i = 0; i < lenMin; ++i) {
            char epochCom = strs[0][i];
            for (int j = 0; j < strs.size() ; ++j) {
                // 3. 一言不合就退出
                if(epochCom != strs[j][i])
                    return comm;
            }
            comm += epochCom;
        }

        // 3. 如果遍历完则返回结果
        return comm;
    }
};

// 解法2：水平扫描（最长公共子串）
// 按照LCP(s1,...,sN) = LCP(LCP(LCP(s1,s2),s3),...,sN)的思路，
// 先求LCP(s1,s2),再求LCP(LCP(s1,s2),s3),以此类推，如果中间得到空字符串，则返回空字符串，如果遍历结束，则得到LCP(s1,s2,...,sN)。
// Tip:使用string 类提供的find函数
// 同样能够通过，但是就比较慢了。
// 复杂度分析： 时间复杂度 O（S），S表示所有字符总个数
// 复杂度分析： 空间复杂度 O(1), 只用了一个字符串来做记录。
 class Solution2 {
 public:
     string longestCommonPrefix(vector<string>& strs) {
         // 0. 边界判断
         if(strs.size() == 0)
             return "";

         // 1. 默认LCP为第一个字符串
         string comm = strs[0];

         // 2. 开始遍历
         for (int i = 1; i < strs.size(); ++i) {
             while (strs[i].find(comm) != 0)  // 只要共同字符串不再开头就开始缩减
             {
                 comm.pop_back();                        // 删除string 最后一个字符串的方法1
                 // comm = comm.substr(0, comm.size()-1);   // 删除string 最后一个字符串的方法2

                 // 如果为空，则返回即可
                 if(comm == "")
                     return comm;
             }
         }

         // 3. 遍历结束，返回结果
         return comm;
     }
 };


// 解法3：分治法，题目介绍页有解题思路
// LCP(s1,s2,...,sN) = LCP(LCP(s1,...,sk),LCP(sk+1,...,sN)),然后再继续分
// 复杂度分析：时间复杂度O(S),S表示所有字符总个数,S = m*n
// 复杂度分析：空间复杂度O(m*log(n),需要保存递归调用，递归调用log(n)次，每次需要空间m去保存。所以一共是O(m*log(n))。
class Solution3 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // 0. 边界判断
        if (strs.size() == 0)
            return "";

        return longestCommonPrefix(strs, 0, strs.size()-1);

    }


    // 分治问题：分左右,也算是递归吧
    string longestCommonPrefix(vector<string> &strs, int left, int right) {
        if (left == right)  // 分治到终点
        {
            return strs[left];
        } else {
            int middle = (left + right) / 2;
            string lcpLeft = longestCommonPrefix(strs, left, middle);
            string lcpRight = longestCommonPrefix(strs, middle + 1, right);

            return commonPrefix(lcpLeft,lcpRight);
        }
    }

    // 子问题的解决
    string commonPrefix(string left, string right) {
        int min = left.size() <= right.size() ? left.size() : right.size();
        string comm = "";
        for (int i = 0; i < min; ++i) {
            if (left[i] == right[i]) {
                comm += left[i];
            } else {
                return comm;
            }
        }

        return comm;
    }

};


// 解法4：二分查找
// 看leetcode原题解的图像上有直观的解释：二分就是将范围不断一分为二，如果满足条件，则范围向后拓展，如果不满足，则范围向前拓展。
// 复杂度分析：时间复杂度 O(S*log(n)),S表示所有的字符数，一共迭代了log(n)轮，每次比较了S=m*n次。
// 复杂度分析：空间复杂度 O(1),只保存几个变量

class Solution4 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // 0. 边界判断
        if (strs.size() == 0 || strs.empty())
            return "";

        // 1. 寻找最短长度（之后只在这个长度内搜索）
        int lenMin = UINT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            if (lenMin > strs[i].size()){
                lenMin = strs[i].size();
            }
        }

        // 2. 开始二分查找
        int low = 1;
        int high = lenMin;
        while (low <= high)
        {
            // 找中点
            int middle = (low + high) / 2;

            // 判断从0到Middle这段字符串是不是大家的公共前缀字符串
            if(isCommonprefix(strs, middle))
            {
                low = middle + 1;
            } else{
                high = middle - 1;
            }
        }

        return strs[0].substr(0, (low+high)/2); // substr(pos，n)包括n。
    }


    bool isCommonprefix(vector<string> &strs, int len)
    {
        string comm = strs[0].substr(0, len);
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].find(comm) != 0)
                return false;
        }

        return true;
    }
};
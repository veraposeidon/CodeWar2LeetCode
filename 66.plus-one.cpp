/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.61%)
 * Total Accepted:    352.8K
 * Total Submissions: 867.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
#include <cmath>
#include <string>
#include <vector>
#include <c++/algorithm>
#include <c++/iostream>
#include <c++/sstream>

using namespace std;

// 解法一： 转成数字，+1，再转成vector
// 最大的问题就溢出。
// 原理上走通，但是字符串长度不限制，影响了数据类型的设置，最长64位也不够用了。
class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 0. 边界条件
        if(digits.size() == 0 || digits.empty())
            return vector<int>(0);
        
        // 1. 转成数字
        int len = digits.size();
        long long number = 0;
        for(int i = 0; i < len; i++)
        {
            long long digitN = pow(10, len - i - 1) * (digits[i]);
            number +=  digitN ;
        }

        // 2. 加一
        number += 1;

        // 3. 数字转成vector
        vector<int> result(0);
        while(number!=0)
        {
            int digit = number % 10;
            result.push_back(digit);
            number = number / 10;
        }
        
        reverse(result.begin(), result.end());

        return result;
    }
};



// 解法二：按照进位的原则进行叠加，进位则往上一位加1
// 需要注意的是，为应对999+1 = 1000的出现，要最终判断进位的存在，存在则在数组顶部添加1.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 0. 边界条件
        if(digits.size() == 0 || digits.empty())
            return vector<int>(0);

        // 1. 拓展数组长度，首位填0
        bool carry = false;
        for (int i = digits.size() - 1; i >= 0 ; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if(digits[i] == 0)
                carry = true;
            else
            {
                carry = false;
                break;
            }
        }

        // 2. 判断是否顶部插入1
        if(carry)
            digits.insert(digits.begin(), 1);


        return digits;
    }
};


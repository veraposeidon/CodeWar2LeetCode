/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (41.81%)
 * Total Accepted:    507.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 转成字符串的确是很简单的事情，不通过转换成字符串判断回文的话：
 * 
 *  1. 负数肯定不是，0肯定是。
 *  2. 通过翻转之后与翻转前是否相等来判断是否回文。这就可以调用之前的翻转数字功能了。
 *
 * 
 */


// 方案一：调用数字反转功能
//class Solution {
//public:
//    int reverse(int x) {
//        // inverse the number
//        long long inversN = 0; // 定义一个较大的数来防止溢出。
//
//        while(x!=0)
//        {
//            // 最后一位
//            int pop = x % 10;
//            x = x / 10;
//            inversN = inversN*10 + pop;
//        }
//
//        return inversN;
//    }
//
//
//    bool isPalindrome(int x) {
//        if (x<0) return false; // 之前的翻转有诈
//        long long revN = reverse(x);
//        if (x == revN)
//            return true;
//        else
//            return false;
//    }
//};

// 方案二：从尾部开始构建反转的数字，一直到剩余部分的数字开始小于等于后半部分的翻转数字
// 举例：1221 -> 1221/10=122,1221%10=1 -> 122/10=12,122%10=2,1*10+2=12,12==12,结束
class Solution {
public:

    bool isPalindrome(int x) {
        if (x<0) return false; // 负数必然不可能
        if (x%10==0 && x!=0) return false; //最后一位为0的必然不可能

        int reverseLast = 0;

        while (x>reverseLast)
        {
            reverseLast = reverseLast*10 + x%10;
            x = x / 10;
        }

        // 双数数字 1221 123321
        if (x == reverseLast)
            return true;

        // 单数数组 12321 345543
        if (x == reverseLast / 10)
            return true;

        return false;
    }
};


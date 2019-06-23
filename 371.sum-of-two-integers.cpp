/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */
class Solution {
public:
    // 通过忽略进位相加和记录进位来进行叠加
    int getSum(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        long long nocarry = a^b;
        long long withcarry = ((a&b)&0xffffffff)<<1;  // 转变成八位的

        return getSum(nocarry, withcarry);  // 直到其中一个值为零即可
    }
};


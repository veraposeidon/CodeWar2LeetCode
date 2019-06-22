/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;

        double half = myPow(x, n / 2);
        // 偶数
        if (n % 2 == 0) return half * half;

        // 奇数
        if (n > 0) return half * half * x;

        // 负数
        return half * half / x;
    }
};


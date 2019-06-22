/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
// 不能用乘法、除法和取余，只能做位操作。
class Solution {
public:
    int divide(int dividend, int divisor) {
        // INT_MIN = -2147483648 ,除以-1就溢出了
        if(divisor==0 || (dividend==INT_MIN&&divisor==-1)) return INT_MAX;

        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;

        int sign = ((dividend<0)^(divisor<0))?-1:1; // 结果正负

        if(n==1) return sign==1?m:-m;
        while (m>=n)
        {
            long long t = n, p = 1;
            while (m>=(t<<1))
            {
                t<<=1;  // 能够整除的变量
                p<<=1;  // 整除的除数
            }
            res += p;
            m -= t;
        }
        return sign==1?res:-res;
    }
};


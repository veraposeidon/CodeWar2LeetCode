/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */
// 由2和5的数量决定
// 这种复杂度高
class Solution1 {
public:
    int trailingZeroes(int n) {
        int two=0,five=0;
        for (int i = 1; i <= n; i++)
        {
            int number = i;
            while (number%2==0 && number>0)
            {
                two += 1;
                number /= 2;
            }
            while (number%5==0 && number>0)
            {
                five += 1;
                number /= 5;
            }
        }
        return min(two, five);
    }
};

// 受到5个个数限制
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n)
        {
            ret += n/5;
            n/=5;
        }
        return ret;
    }
};


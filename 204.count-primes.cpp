/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.24%)
 * Total Accepted:    217.2K
 * Total Submissions: 766K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */
// 厄拉多塞 筛选法
class Solution {
public:
    int countPrimes(int n) {
        if ( n<=1 ) {
            return 0;
        }

        // 
        vector<bool> notPrime(n, false);
        int count = 0;

        for(int i = 2; i < n; i++)
        {
            if (notPrime[i] == false) {
                count++;

                for(int j = 0; j*i < n; j++)
                {
                    notPrime[i*j] = true;
                }
            }
        }

        return count;
        

        
    }
};


/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (43.44%)
 * Total Accepted:    363.6K
 * Total Submissions: 834.5K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

// 容易理解的方法是递归
// 但是递归太占资源，第二个是重复计算了。
// 时间复杂度: O(2^n)
// 空间复杂度: O()
class Solution1 {
public:
    int climbStairs(int n) {
        // 0.
        if ( n <= 0 ) {
            return 0;
        }

        if ( n == 1 ) {
            return 1;
        }

        if ( n == 2 ) {
            return 2;
        }
        
        return climbStairs(n-1) + climbStairs(n-2);  
    }
};


// 斐波那契数列 与 动态规划
// 时间复杂度O(n)
// 空间复杂度O(1)
class Solution2 {
public:
    int climbStairs(int n) {
        // 0.
        if ( n <= 0 ) {
            return 0;
        }

        if ( n == 1 ) {
            return 1;
        }

        if ( n == 2 ) {
            return 2;
        }
        
        // 将递归转为动态规划
        int formerformer = 1;
        int former = 2;
        int now = 0;
        for(int i = 3; i <= n; i++)
        {
            now = former + formerformer;
            formerformer = former;
            former = now;
        }

        return now;
    } 
};


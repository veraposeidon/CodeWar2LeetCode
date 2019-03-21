/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.10%)
 * Total Accepted:    223.5K
 * Total Submissions: 318.9K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
// 汉明距离
// 方案： 先异或，再统计1的个数
// 时间复杂度： O(1)
// 空间复杂度： O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ord = x^y;
        return hammingWeight(ord);

    }

    int hammingWeight(int n) {
        int count = 0;
        while( n != 0){
            count ++;
            n &= (n-1);
        }

        return count;
    }
};


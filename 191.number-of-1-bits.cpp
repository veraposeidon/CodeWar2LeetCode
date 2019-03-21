/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (41.99%)
 * Total Accepted:    245.1K
 * Total Submissions: 580.2K
 * Testcase Example:  '00000000000000000000000000001011'
 *
 * Write a function that takes an unsigned integer and return the number of '1'
 * bits it has (also known as the Hamming weight).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 00000000000000000000000000001011
 * Output: 3
 * Explanation: The input binary string 00000000000000000000000000001011 has a
 * total of three '1' bits.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 00000000000000000000000010000000
 * Output: 1
 * Explanation: The input binary string 00000000000000000000000010000000 has a
 * total of one '1' bit.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 11111111111111111111111111111101
 * Output: 31
 * Explanation: The input binary string 11111111111111111111111111111101 has a
 * total of thirty one '1' bits.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, the input will be given as signed integer type and should not
 * affect your implementation, as the internal binary representation of the
 * integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 3 above the input represents the signed
 * integer -3.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 */

// 解决思路：通过左移来进位，通过与操作来计算
// 循环左移
// 时间复杂度： O(1) 32位只需移动32次
// 空间复杂度： O(1)
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mask = 1;  // 要注意这个数据类型要一致
        for(int i = 0; i < 32; i++)     // uint左移31位即可
        {
            if ( (n&mask) ) {
                 count ++;
            }
            mask = mask << 1;  // 乘二
        }
        return count;
    }
};


// 位操作技巧
// 通过n与n-1的与操作，能够找到最后一位不为零的比特。
// 每一轮都进行这样的操作，直到n变为0
// 时间复杂度O(1) 小于32
// 空间复杂度O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while( n != 0){
            count ++;
            n &= (n-1);
        }
        
        return count;
    }
};

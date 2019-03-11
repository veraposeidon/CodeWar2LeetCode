/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.52%)
 * Total Accepted:    261.7K
 * Total Submissions: 660.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:

    string generate(string input)
    {
        int count = 0;
        char ch = input[0];
        string out = "";
        for(int i = 0; i < input.size(); i++)
        {
            if ( input[i] == ch  ) {
                count ++;
            }else
            {
                out += (count + '0');
                out += ch;

                ch = input[i];
                count = 1;
            }
        }

        out += (count + '0');
        out += ch;

        return out;
        
    }


    string countAndSay(int n) {
        // 0. 
        if (n<=0 && n>30) {
            return "";
        }

        // 1. 
        string str="1";
        for(int i = 2; i <= n; i++)
        {
            str = generate(str);
        }
        
        // 2.
        return str;
        
    }
};


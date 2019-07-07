/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
class Solution {
public:
    // 找规律
    // 第i位与第j位相乘，影响第i+j和i+j+1位
    string multiply(string num1, string num2) {
        // check
        if(num1=="0" || num2=="0") return "0";
        
        int len1 = num1.size(), len2 = num2.size();
        vector<int> plus(len1+len2, 0);
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                plus[len1+len2-2-i-j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        
        string res = "";
        
        for(int i=0;i<len1+len2-1;i++){
            plus[i+1] += plus[i] / 10;
            plus[i] = plus[i] % 10;
            res = char(plus[i]+'0') + res;
        }
        
        if(plus[len1+len2-1] != 0){
            res = char(plus[len1+len2-1]+'0') + res;
        }
        
        return res;
    }
};

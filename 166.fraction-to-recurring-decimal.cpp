/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // check
        if(numerator==0) return "0";
        if(denominator==0) return "";
        // 正负
        string sign = ((numerator<0)^(denominator<0))?"-":"";
        // 类型转换防止溢出
        long num = numerator;
        num = abs(num);
        long den = denominator;
        den = abs(den);
        // 商
        long major = num / den;
        // 余数
        long rem = num % den;
        // 能被除尽就直接返回
        if(rem==0){
            return sign + to_string(major);
        }

        // 构建哈希表来判断余数重复（余数重复表示会有循环）
        string res = sign + to_string(major) + ".";
        unordered_map<long, int> map;   // 余数，下标
        while (rem != 0)
        {
            if(map.count(rem)){
                int index = map[rem];
                res.insert(index, "(");
                res += ")";
                break;  // 结束
            }else{
                // 不够借一位，把商放入小数
                res += to_string(rem*10/den);
                map[rem] = res.size()-1;  // 记录下标
            }
            rem = rem*10%den;
        }
        return res;
    }
};


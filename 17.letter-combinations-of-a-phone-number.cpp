/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    const string letterMap[10]={
        " ",    //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz", //9
    };

    vector<string> result;

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return vector<string>();
        }

        findCombinations(digits, 0, "");

        return result;
    }

    void findCombinations(const string &digits, int index, const string &s){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }

        // 
        char ch = digits[index];
        string letter = letterMap[ch - '0'];

        for (int i = 0; i < letter.size(); i++)
        {
            findCombinations(digits, index+1, s + letter[i]);
        }
        return;
    }
};


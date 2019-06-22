/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
// 
class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;
        while (n!=1)
        {
            if(visited.count(n)) return false;
            visited.insert(n);
            
            vector<int> result = split(n);
            int sum=0;
            for(int item:result){
                sum += item*item;
            }
            
            n = sum;
        }

        return true;
        
    }

    vector<int> split(int number){
        vector<int> result;
        while (number > 0)
        {
            result.push_back(number % 10);
            number = number / 10;
        }
        return result;
    }
};


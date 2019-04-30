/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */
// 解法：双指针来考虑问题。最小的重量匹配最大的重量，行则同时上船。不行则重者独自一条船
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // 0. check
        if (people.empty()) {
            return 0;
        }

        // 1. sort by wight
        sort(people.begin(), people.end());

        // 2. bi pointers
        int prior = 0;
        int last = people.size() - 1;

        int num = 0;
        // 3. while loop
        while(prior < last){
            int sum = people[prior] + people[last];
            if (sum > limit) {
                last--;
                num++;
            }else{
                prior++;
                last--;
                num++;
            }
        }
        if (prior == last) {
                num++;
        }
        return num;
    }
};


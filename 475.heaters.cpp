/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 0. check
        if (houses.empty() || heaters.empty()) 
            return 0;
        
        // 1. sort id
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        // 2. variable recording
        int result = 0;
        int temp = 0;
        int heaterID = 0;
        
        // 3. loop houses, fing minimal warm radius
        for(int i = 0; i < houses.size(); i++)
        {
            // find heater on the right side of the house
            while(heaterID < heaters.size() && heaters[heaterID] < houses[i]){
                heaterID ++;
            }
            // conditions
            if (heaterID == heaters.size()) {
                temp = houses[i] - heaters[heaterID-1]; // there's no heater on the right side of this house
            }
            else if(heaterID == 0){
                temp = heaters[heaterID] - houses[i];   // there's no heater on the left side of this house
            }else{
                temp = min(heaters[heaterID] - houses[i], houses[i] - heaters[heaterID-1]); // choose the smaller
            }
            
            if(temp > result)
                result = temp;
        }
        
        return result;
    }
};


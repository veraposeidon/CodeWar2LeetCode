/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
public:
//     // 一种解法是先排序，然后用动态规划找最大
//     int longestConsecutive(vector<int>& nums) {
//         // 
//         if(nums.empty()) return 0;
        
//         sort(nums.begin(), nums.end());
//         int maxL=1;
//         int temp=1;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]+1){
//                 temp += 1;
//                 maxL = max(maxL, temp);
//             }else if(nums[i]!=nums[i-1]){
//                 temp = 1;
//             }
//         }
//         return maxL;
//     }
    // 另外一种解法是使用哈希表
    // 先一遍注册，然后再
    int longestConsecutive(vector<int>& nums) {
        // 
        if(nums.empty()) return 0;
        
        // 整数 和 最大长度
        unordered_map<int, int> map;
        int max_len = 1;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])) continue;   // 存在该元素 跳过
            
            map[nums[i]] = 1;
            // 前一个元素存在
            if(map.count(nums[i]-1)){
                int left = nums[i]-1 - map[nums[i]-1] + 1;
                int right = nums[i] + map[nums[i]] - 1;
                int len = right - left + 1;
                max_len = max(max_len, len);
                map[left] = len;
                map[right] = len;
            }
            
            // 后一个元素存在
            if(map.count(nums[i]+1)){
                int left = nums[i] - map[nums[i]] + 1;
                int right = nums[i]+1 + map[nums[i]+1] - 1;
                int len = right - left + 1;
                max_len = max(max_len, len);
                map[left] = len;
                map[right] = len;
            }
        }
        
        
        
        return max_len;
    }
};

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    // 多种方案，记录一种最简单的
    // 找到最高的柱子，分左右来判断
    // 这种方案貌似只能使用在只有一个最高柱子的场景
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        
        int max_idx = max_element(height.begin(), height.end()) - height.begin();
        
        int left_h = 0;
        int area = 0;
        for(int i=0;i<max_idx;i++){
            if(height[i]<left_h){
                area += left_h - height[i]; 
            }else{
                left_h = height[i];
            }
        }
        int right_h=0;
        for(int i=height.size()-1;i>max_idx;i--){
            if(height[i]<right_h){
                area += right_h - height[i]; 
            }else{
                right_h = height[i];
            }
        }
        
        return area;
    }
};


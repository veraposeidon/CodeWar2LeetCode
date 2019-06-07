/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// 暴力法
// 双指针确定宽度，找区间内最小确定高度
// 通过 94/96 时间复杂度高，越 O(n^3)
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 0. check
        if(heights.empty())
            return 0;
        
        int max_area=0;
        // 1. for loop 
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = i; j < heights.size(); j++)
            {
                int width = j - i + 1;
                int minheight = *(min_element(heights.begin()+i, heights.begin()+j+1));
                int area = width * minheight;
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

// 用单调递增栈来维护高度序列
// 遇到小于栈顶的数字则进行来求解。
// trick在于最后追加一个0高度，用来触发整个数组的面积计算。
// 不用太高级，用两个栈来维护好了。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 0. check
        if(heights.empty())
            return 0;
        
        int max_area=0;
        stack<int> pos; // 递增栈 记录每一段高度的起始位置
        heights.push_back(0);    // trick

        // 1. for loop
        for (int i = 0; i < heights.size(); i++)
        {
            // 遇矮则进行计算
            while(!pos.empty() && heights[pos.top()] >= heights[i])
            {
                // 计算之前的面积
                int cur = pos.top();
                pos.pop();  // 弹出是为了漏出起始位置

                int area = heights[cur] * (pos.empty() ? i:(i-pos.top()-1));
                max_area = max(max_area, area);
            }
            pos.push(i);    // 遇高 维护栈顶
        }
        return max_area;
    }
};




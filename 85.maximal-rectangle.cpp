/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// 解法：化解为按行统计histogram
class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        // 0. check
        if(heights.empty())
            return 0;
        
        int max_area=0;
        stack<int> pos; // 递增栈 记录每一段高度的起始位置
        heights.push_back(0);    // trick   // 注意不能修改原始数组

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        vector<int> hist(matrix[0].size(), 0);  // 初始化为0

        int max_area = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < hist.size(); j++)
            {
                if(matrix[i][j] == '0')
                    hist[j] = 0;
                else
                    hist[j] += 1;
            }

            int tempArea = largestRectangleArea(hist);
            max_area = max(max_area, tempArea);
        }
        
        return max_area;
    }
};


/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        vector<int> res;
        while(left <= right || top <= bottom) {
            // left2right
            for (int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top += 1;
            if (top > bottom) break;
            // top2bottom
            for (int i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            right -= 1;
            if (right < left) break;
            //  right2left
            for (int i=right;i>=left;i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom -=1;
            if (bottom < top) break;
            // bottom2top
            for (int i=bottom;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left += 1;
            if (left > right) break;
        }
        return res;
    }
};
// @lc code=end


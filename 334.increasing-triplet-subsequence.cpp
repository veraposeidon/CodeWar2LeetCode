/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.47%)
 * Total Accepted:    88.1K
 * Total Submissions: 223.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 */
// 递增三元子序列
// 解法一： 暴力不可取，时间复杂度O(n^3)
// 解法二：动态规划思想（最长递增子序列问题），时间复杂度O(n^2)，空间复杂度O(n^2)
// 解法三：要求时间复杂度为O(n).分别用两个数来标记最小和次小的数
// O（n）解法
class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for(int i: nums){
            if(i<=c1)
                c1 = i;     // 最小
            else if(i<=c2)
                c2 = i;
            else
                return true;       
        }
        return false;
    }
};

// 动态规划解法求递增子序列
// 讲解可参考： https://www.kancloud.cn/digest/pieces-algorithm/163625
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 0. 判空
        if (nums.empty()) {
            return false;
        }

        // 1. 构建动态矩阵,记录最长子串长度
        vector<vector<int> > dp_table(nums.size(), vector<int>(nums.size(), 0));
        for(int i = 0; i < nums.size(); i++)
        {
            dp_table[i][i] = 1; // 对角线为1
            for(int j = 0; j < i; j++)
            {
                if(nums[i] <= nums[j])
                    dp_table[i][j] = 1;
                else{
                    // L_j = max(L_i) + 1
                    auto iter = max_element(dp_table[j].begin(), dp_table[j].end());
                    dp_table[i][j] = *iter + 1; // 最长长度在原来最长长度基础上加一
                    // 直接判断得了要是出现3就说明有大于三位的
                    if( dp_table[i][j] >= 3)
                        return true;
                }
            }
        }

        // 2. 判断动态矩阵最后一行，找最大值就知道最长长度了
        // TODO: 应该遍历每一行的最大值
        // auto iter = max_element(dp_table[nums.size()-1].begin(),dp_table[nums.size()-1].end());
        // if(*iter >= 3)
        //     return true;
        
        return false;
    }
};
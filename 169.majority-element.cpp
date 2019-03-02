/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.37%)
 * Total Accepted:    348.7K
 * Total Submissions: 677.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// 解法一：构建哈希表
// 时间复杂度O(n)
// 空间复杂度O(n)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        // 0. 边界条件. 非空就不判断了，省时间
        // if(nums.size()==0 || nums.empty())
        //     return 0;

        // 1. 构架哈希表
        unordered_map<int, int> num_counts;

        // 2. 遍历过程中找最大值
        int maxnum = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(num_counts.find(nums[i]) != num_counts.end())
            {
                num_counts[nums[i]] ++;
            }else
            {
                num_counts[nums[i]]= 1;
            }

            if(num_counts[nums[i]] > num_counts[maxnum])
                maxnum = nums[i];
            
            // 过半即可返回
            if(num_counts[maxnum] > nums.size()/2)
                return maxnum;
        }

        // 3. 返回
        return maxnum;
    }
};

// 解法二：排序，处在中间的必然是最多的
// 排序时间复杂度：O(NlogN),空间复杂度O(1)或者O(n)。允许操作原数组不需要空间，不允许需要拷贝
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        // 0. 边界判断
        // 1. 排序
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};


// 解法三：分治法
// 分治法也很有意思，需要有一个统计区段内某数个数的功能。
class Solution3 {
public:
    // 计数 函数
    int countInt(vector<int>& nums, int num, int low, int high)
    {
        int count = 0;

        for(int i = low; i <= high; i++)
        {
            if (nums[i] == num) {
                count++;
            }
        } 
        return count;
    }

    // 调用函数
    int majorDevideConq(vector<int>& nums, int low, int high)
    {
        // 结束条件
        if (low == high) {
            return nums[low];
        }

        // 搜索两边频次最高的数
        int mid = (low+high)/2;
        int left = majorDevideConq(nums, low, mid);
        int right = majorDevideConq(nums, mid+1, high);

        // 如果相同则返回即可
        if (left == right) {
            return left;
        }
        
        // 否则需要判断在区间内哪个频次更高
        int leftCount = countInt(nums, left, low, high);
        int rightCount = countInt(nums, right, low, high);

        return leftCount> rightCount ? left:right;
        
    }
    
    int majorityElement(vector<int>& nums) {
        // 0. 边界判断

        // 1. 
        return majorDevideConq(nums, 0, nums.size()-1);
        
    }
};

// 解法四：随机法
// 理论上，两遍就可以出来最大值，因为占了二分之一。技术上也可能出现一直找不到最大值的情况
class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand((unsigned)time(NULL)); //随机种子

        while(true){
            int idx = rand() % n;
            int candidate = nums[idx];
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if (nums[i]==nums[idx]) {
                    count++;
                }
            }
            if(count > n/2)
                return candidate;
        }
    }
};

// 解法五：Moore 投票法（线性）
// 用投票的思路来就是，支持者加一票，反对者减一票，最后肯定会出现的是超过二分之一的
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(!counts)
            {
                major = nums[i];
                counts = 1;
            }
            else
            {
                counts += (nums[i]==major)?1:-1;
            } 
        }
        
        return major;
    }
};


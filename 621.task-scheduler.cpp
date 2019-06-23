/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
// 按频数从高到底安排才行。
// 要考虑任务类型多还是任务间隔大
// https://zhanghuimeng.github.io/post/leetcode-621-task-scheduler/
class Solution {
public:
    // 贪心算法
    // 无所谓具体任务，只考虑频率
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskLeft(26,0);
        // 统计频率
        for(char ch : tasks){
            taskLeft[ch-'A']++;
        }
        // 排序
        sort(taskLeft.begin(), taskLeft.end());
        // 统计频次最高的元素数目
        int maxes = 0;
        for (int i = 25; i>=0&&taskLeft[i]==taskLeft[25]; i--)
        {
            maxes++;
        }
        // 两种形式：一种形式为间隔比任务数量大，即存在间隔，时间总数为 （频率最高任务数目-1）*（间隔+1）+（频率最高任务数目）
        // 第二种形式为间隔比任务数量小，那么怎么安排都是全满即可。
        return max((int)tasks.size(), (taskLeft[25]-1)*(n+1)+maxes);
    }
};


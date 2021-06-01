/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    // 单向BFS
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        unordered_set<string> visited;
        for (string s : deadends) {
            dead.insert(s);
        }

        queue<string> queue;
        int step = 0;
        queue.push("0000");
        visited.insert("0000");

        while (queue.size()) {
            int sz = queue.size();
            for (int i = 0; i < sz; i++) {
                string cur = queue.front();
                queue.pop();
                if (dead.count(cur)) {
                    continue;
                }
                if (cur == target) 
                {
                    return step;
                }
                
                for (int i = 0; i < 4; i++)
                {
                    string up = plusOne(cur, i);
                    if (!visited.count(up))
                    {
                        queue.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, i);
                    if (!visited.count(down))
                    {
                        queue.push(down);
                        visited.insert(down);
                    }
                } 
            }
            step++;
        }
        return -1;
    }

    string plusOne(string s, int n) {
        if (s[n] == '9')
        {
            s[n] = '0';
        } else {
            s[n] += 1;
        }
        return s;
    }

    string minusOne(string s, int n) {
        if (s[n] == '0')
        {
            s[n] = '9';
        } else {
            s[n] -= 1;
        }
        return s;
    }
};
// @lc code=end


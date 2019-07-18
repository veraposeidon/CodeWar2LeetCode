/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */
class Solution {
public:
    //  BFS搜索
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;    // 队列
        unordered_set<string> used; // 禁止访问集合
        for(auto &str:deadends){
            used.insert(str);
        }

        string cur = "0000";
        if(used.count(cur)) return -1;
        
        q.push(cur);
        used.insert(cur);

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                cur = q.front();
                string back = cur;
                if(cur == target) return steps;

                for(int j=0;j<4;++j){
                    // 加一
                    cur[j] = (cur[j]-'0'-1+10)%10+'0';
                    if(!used.count(cur)){
                        q.push(cur);
                        used.insert(cur);
                    }
                    cur = back;
                    // 减一
                    cur[j] = (cur[j]-'0'+1)%10+'0';
                    if(!used.count(cur)){
                        q.push(cur);
                        used.insert(cur);
                    }
                    cur = back;
                }
                q.pop();
            }
            ++steps;
        }
        return -1;
    }
};


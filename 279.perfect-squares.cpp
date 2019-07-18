/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
class Solution {
public:
    // BFS 搜索
    int numSquares(int n) {
        if(n==0 || n==1) return n;
        
        queue<int> q;
        unordered_set<int> used;

        q.push(n);
        used.insert(n);
        int res=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                int cur = q.front();
                if(cur == 0) return res;
                int sqrt_n = int(sqrt(cur));
                for(int i=1;i<=sqrt_n;++i){
                    int remain = cur - i*i;
                    if(!used.count(remain)){
                        used.insert(remain);
                        q.push(remain);
                    }
                }
                q.pop();
            }
            ++res;
        }

        return -1;
    }
};



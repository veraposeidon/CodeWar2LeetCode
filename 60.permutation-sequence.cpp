/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
class Solution {
public:
//     // 深度优先遍历，然后再进行计数
//     // DFS会超出时间
//     string res;
//     string getPermutation(int n, int k) {
//         vector<bool> visited(n, false);
        
//         int count = 0;
//         dfs(visited, "", count, k);
        
//         return res;
//     }
    
//     void dfs(vector<bool>& visited, string out, int& count, int k){
//         // 终止条件
//         if(out.size() == visited.size()){
//             count += 1; // 累加
//             if(count == k){
//                 res = out;
//             }
//             return;
//         }
        
//         if(count < k){
//             for(int i=1;i<=visited.size();i++){
//                 if(visited[i-1]) continue;
                
//                 visited[i-1] = true;
//                 dfs(visited, out+to_string(i), count, k);
//                 visited[i-1] = false;
//             }
//         }
        
//         return; 
//     }
    
    // 按照统计规律来
    int factorial(int n){
        int result = 1;
        for(int i=1;i<=n;i++){
            result *= i;
        }
        return result;
    }
    
    
    string getPermutation(int n, int k) {
        vector<bool> used(n, false);
        string result = "";
        k = k - 1;
        for(int i=1;i<=n;i++){
            int smaller = k / factorial(n-i);
            smaller += 1;
            for(int i=1;i<=n;i++){
                if(!used[i-1]){
                    smaller -= 1;
                    if(smaller == 0){
                        result += to_string(i);
                        used[i-1] = true;
                    }
                }
            }
            k = k %  factorial(n-i);
        }
        

        return result;
    }
};


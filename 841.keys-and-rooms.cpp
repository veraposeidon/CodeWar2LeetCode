/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
class Solution {
public:
    // DFS // 保存visited
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(auto bo : visited){
            if(!bo) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int ID){
        if(visited[ID]) return;
        
        visited[ID] = true;
        
        for(auto id : rooms[ID]){
            dfs(rooms, visited, id);
        }
    }
};


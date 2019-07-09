/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.02%)
 * Total Accepted:    265.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2  capacity );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */

class LRUCache {
public:
    struct dLink{
        int val;
        int key;
        dLink *next, *prev;
        dLink(int x, int y) : val(x),key(y),next(NULL), prev(NULL) {}
    };
    
    // 双向链表 + 哈希表来实现
    LRUCache(int capacity) {
        cpcty = capacity;
    }
    
    int get(int key) {
        // 查询有无
        if(map.count(key)==0) return -1;
        
        // 更新该节点到head
        dLink* temp = map[key];
        // head节点不动
        if(temp != head){
            // 其他节点
            temp->prev->next = temp->next;
            // tail节点要更新tail
            if(temp == tail)
            {
                tail = temp->prev;
                tail->next = NULL;
            }else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
            
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        
        return head->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)!=0){
            // 有该节点,直接交换
            // 改该节点值
            dLink *temp = map[key];
            temp->val = value;
            
            if(temp != head){
             
                // tail节点要更新tail
                if(temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                }else{
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }

                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            
        }else{
            // 无该节点
            dLink *newnode = new dLink(value, key);
            if(map.empty()){
                // 第一个节点
                head = newnode;
                tail = newnode;
            }else{
                newnode->next = head;  
                head->prev = newnode;
                head = newnode;
            }
            
            map[key] = newnode;
            
            // 判断是否超了
            if(map.size() > cpcty){
                dLink *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                
                map.erase(temp->key);
                delete temp;
            }
            
            
        }
    }
private:
    int cpcty;
    dLink *head, *tail;
    // key -> node
    unordered_map <int, dLink*> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




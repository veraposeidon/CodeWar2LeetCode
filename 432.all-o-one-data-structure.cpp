/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */
class AllOne {
public:

    
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {       
        if(!map.count(key)){
            if(buckets.empty() || buckets.back().val != 1){
                // 为空或者没有值为1的节点
                auto newBucket = buckets.insert(buckets.end(), {1, {key}});
                map[key] = newBucket;
            }else{
                auto newBucket = --buckets.end();   // end-1才是最后一个
                newBucket->keys.insert(key);
                map[key] = newBucket;
            }
        }else{
            auto curBucket = map[key], lastBucket = (--map[key]);
            if(lastBucket == buckets.end() || lastBucket->val != curBucket->val+1){
                auto newBucket = buckets.insert(curBucket, {curBucket->val+1, {key}});  // 已存在但不连续
                map[key] = newBucket;
            }else{
                lastBucket->keys.insert(key);
                map[key]=lastBucket;
            }
            curBucket->keys.erase(key);
            if(curBucket->keys.empty()) buckets.erase(curBucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!map.count(key)) return;
        auto curBucket = map[key];
        if(curBucket->val == 1){
            curBucket->keys.erase(key);
            if(curBucket->keys.empty()) buckets.erase(curBucket);
            
            map.erase(key);
            return;
        }
        
        auto nextBucket = ++map[key];
        if(nextBucket == buckets.end() || nextBucket->val != curBucket->val-1){
            auto newBucket = buckets.insert(nextBucket,{curBucket->val-1, {key}});
            map[key] = newBucket;
        }else{
            nextBucket->keys.insert(key);
            map[key]=nextBucket;
        }
        curBucket->keys.erase(key);
        if(curBucket->keys.empty()) buckets.erase(curBucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty()?"":*(buckets.begin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
         return buckets.empty()?"":*((--buckets.end())->keys.begin());
    }

private:
    struct bucket{
        int val;
        unordered_set<string> keys;
    };
    list<bucket> buckets;
    unordered_map<string, list<bucket>::iterator> map;  // 哈希表
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */



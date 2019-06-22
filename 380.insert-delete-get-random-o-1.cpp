/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
// 通过哈希表与一位数组建立关联的方式来做
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        // TODO
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 数组中追加元素，并以值为键，数组下标为值插入哈希表中。
        if(map.find(val) != map.end()) return false;
        nums.push_back(val);
        map[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;

        int last = nums.back();
        map[last] = map[val];   // 哈希表中更改索引
        nums[map[val]] = last;    // 数组中交换元素
        nums.pop_back();        // 删除最后一个元素
        map.erase(val);         // 哈希表中删除元素
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


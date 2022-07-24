/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {

private:
    vector<Trie *> children;
    bool isWordEnd;

    Trie* searchPrefix(string prefix) {
        Trie* cur = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) {
                return nullptr;
            }
            cur = cur->children[idx];
        }
        return cur;
    }

public:
    Trie() {
        children = vector<Trie*>(26);
        isWordEnd = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new Trie();
            }
            cur = cur->children[idx];
        }
        cur->isWordEnd = true;
    }
    
    bool search(string word) {
        Trie* res = searchPrefix(word);
        return res != nullptr && res->isWordEnd == true;
    }
    
    bool startsWith(string prefix) {
        Trie* res = searchPrefix(prefix);
        return res != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


/*
 * @lc app=leetcode.cn id=208 lang=swift
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

class Trie {
    private var root: Trie?
    private var isEnd: Bool = false
    private var children: [Character: Trie] = [:]

    init() {
        root = self
        isEnd = false
        children = [:]
    }

    func insert(_ word: String) {
        var cur = root
        for char in word {
            if cur?.children[char] == nil {
                cur?.children[char] = Trie()
            }
            cur = cur?.children[char]!
        }
        cur?.isEnd = true
    }

    func search(_ word: String) -> Bool {
        let node = searchPrefix(word)
        return node != nil && node?.isEnd == true
    }

    func startsWith(_ prefix: String) -> Bool {
        let node = searchPrefix(prefix)
        return node != nil
    }

    private func searchPrefix(_ prefix: String) -> Trie? {
        var cur = root
        for char in prefix {
            guard let child = cur?.children[char] else {
                return nil
            }
            cur = child
        }
        return cur
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie()
 * obj.insert(word)
 * let ret_2: Bool = obj.search(word)
 * let ret_3: Bool = obj.startsWith(prefix)
 */
// @lc code=end

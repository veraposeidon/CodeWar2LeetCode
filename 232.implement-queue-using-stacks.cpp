/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s_main.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {        
        while(!s_main.empty()) {
            s_help.push(s_main.top());
            s_main.pop();
        }
        
        auto ele = s_help.top();
        s_help.pop();
        
        while(!s_help.empty()) {
            s_main.push(s_help.top());
            s_help.pop();
        }
        return ele;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s_main.empty()) {
            s_help.push(s_main.top());
            s_main.pop();
        }
        
        auto ele = s_help.top();
        while(!s_help.empty()) {
            s_main.push(s_help.top());
            s_help.pop();
        }
        return ele;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s_main.empty();
    }
private:
    stack<int> s_main;
    stack<int> s_help;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


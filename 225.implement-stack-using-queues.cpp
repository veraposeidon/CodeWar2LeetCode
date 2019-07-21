/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty()){
           q2.push(x);  
        } 
        else{
           q1.push(x); 
        } 
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(this->empty()) return -1;
        
        queue<int> *prev = q1.empty()?&q2:&q1;
        queue<int> *now = q1.empty()?&q1:&q2;
        int len = prev->size()-1;
        while(len){
            now->push(prev->front());
            prev->pop();
            len--;
        }
        auto ele = prev->front();
        prev->pop();
        return ele;
    }
    
    /** Get the top element. */
    int top() {
        if(this->empty()) return -1;
        
        queue<int> *prev = q1.empty()?&q2:&q1;
        queue<int> *now = q1.empty()?&q1:&q2;
        int len = prev->size()-1;
        while(len){
            now->push(prev->front());
            prev->pop();
            len--;
        }
        auto ele = prev->front();
        now->push(ele);
        prev->pop();
        return ele;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
private:
    queue<int> q1,q2;
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


#include<stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    
    stack<int> rs;
    stack<int> s;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty())
            s.push(x);
        else{
            while(!s.empty()){
                int top=s.top();
                rs.push(top);
                s.pop();
            }
            rs.push(x);
            while(!rs.empty()){
                int top=rs.top();
                s.push(top);
                rs.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top=s.top();
        s.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
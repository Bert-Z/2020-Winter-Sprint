#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> minstack;
    stack<int> minnumstack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(minstack.size()==0)
            minnumstack.push(x);
        else{
            if(x<=minnumstack.top())
                minnumstack.push(x);
        } 
        minstack.push(x);
    }
    
    void pop() {
        int minnum=minnumstack.top();
        int popnum=minstack.top();
        if(popnum==minnum)
            minnumstack.pop();
        minstack.pop();
    }
    
    int top() {
        return minstack.top();
    }
    
    int getMin() {
        return minnumstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
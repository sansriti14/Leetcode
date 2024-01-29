class MyQueue {
public:
    stack<int> st1, st2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int front = peek();
        st2.pop();
        return front;
    }
    
    int peek() {
        if(st2.size() == 0) {
            while(st1.size()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        return st2.top();
    }
    
    bool empty() {
        cout<<st1.size()<<" "<<st2.size();
        return (!st1.size() && !st2.size());
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
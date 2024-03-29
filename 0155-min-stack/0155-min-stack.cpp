class MinStack {
public:
    vector<int> arr;
    int minElement;
    
    MinStack() {
        minElement = INT_MAX;
    }
    
    void push(int val) {    
       if (val <= minElement) {
           arr.push_back(minElement);
           minElement = val;
       }
        
       arr.push_back(val);  
    }
    
    void pop() {
       int lastElement = arr.back();
       arr.pop_back();

       if (lastElement == minElement) {
           minElement = arr.back();
           arr.pop_back();
       }
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
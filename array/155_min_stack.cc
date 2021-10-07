class MinStack {
private:
    vector<int> s;
    priority_queue<int, vector<int>, greater<int> > minq;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push_back(val);
        minq.push(val);
    }
    
    void pop() {
        s.pop_back();
        minq.pop();         
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minq.top();
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

class MinStack {
private:
    vector<int> s;
    vector<int> minv;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push_back(val);        
        if (!minv.empty() && val <= minv.back()) {
            minv.push_back(val);
        } else if (minv.empty()) {
            minv.push_back(val);
        }
    }
    
    void pop() {
        int val = s.back();
        s.pop_back();
        if (val == minv.back()) {
            minv.pop_back();
        }
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minv.back();
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

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    bool pushState;
public:
    
    MyQueue() {
        pushState = true;
    }
    
    void push(int x) {
        if (pushState) {
            s1.push(x);            
        } else {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
            pushState = true;                
        }
    }
    
    int pop() {
        if (pushState) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        pushState = false;        
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (pushState) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        pushState = false;
        return s2.top();
    }
    
    bool empty() {
        if (pushState) {
            return s1.empty();
        } else {
            return s2.empty();
        }        
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

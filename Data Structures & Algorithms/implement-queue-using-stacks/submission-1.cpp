class MyQueue {
private:
    stack<int> in;
    stack<int> out;

public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(empty()) return -1;

        if(out.empty()){
            while(!in.empty()){
                int cur = in.top();
                in.pop();
                out.push(cur);
            }
        }

        int res = out.top();
        out.pop();
        return res;
    }
    
    int peek() {
        if(empty()) return -1;
        if(out.empty()){
            while(!in.empty()){
                int cur = in.top();
                in.pop();
                out.push(cur);
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
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
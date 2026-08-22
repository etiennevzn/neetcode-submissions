class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        int qSize = q.size();
        q.push(x);
        for(int i = 0; i < qSize; ++i){
            int elem = q.front();
            q.pop();
            q.push(elem);
        }
    }
    
    int pop() {
        int elem = q.front();
        q.pop();
        return elem;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
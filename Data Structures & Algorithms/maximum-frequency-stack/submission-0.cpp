class FreqStack {
private:
    unordered_map<int,int> freq;
    vector<int> stack;
    priority_queue<pair<int,int>> maxHeap;
public:
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;
        stack.push_back(val);
        maxHeap.push({freq[val], stack.size() - 1});
    }
    
    int pop() {
        auto [f, idx] = maxHeap.top();
        maxHeap.pop();
        int res = stack[idx];
        freq[res]--;
        stack[idx] = -1;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
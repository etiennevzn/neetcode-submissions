class FreqStack {
private:
    vector<stack<int>> stacks;
    unordered_map<int,int> freq;
public:
    FreqStack(){
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        if(++freq[val] == stacks.size()){
            stacks.push_back(stack<int>());
        }
        stacks[freq[val]].push(val);
    }
    
    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        if(stacks.back().empty()) stacks.pop_back();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
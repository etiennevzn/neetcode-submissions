class KthLargest {
public:
    int k_;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int num : nums){
            heap.push(num);
            if(heap.size() > k_) heap.pop();
        }    
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > k_) heap.pop();
        return heap.top();
    }
};

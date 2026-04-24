class MedianFinder {
private:
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, std::greater<int>> largeHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(smallHeap.size() > largeHeap.size() + 1 || (!largeHeap.empty() && smallHeap.top() > largeHeap.top())){
            int temp = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(temp);
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            int temp = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(temp);
        }
    }
    
    double findMedian() {
        int listSize = smallHeap.size() + largeHeap.size();
        if(listSize % 2 == 0){
            int mid1 = smallHeap.top();
            int mid2 = largeHeap.top();

            return (mid1 + mid2) / 2.0;
        }

        if(smallHeap.size() > largeHeap.size()) return smallHeap.top();
        return largeHeap.top();
    }
};

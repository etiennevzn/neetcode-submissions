class MedianFinder {
private:
    vector<int> numList;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        numList.push_back(num);
        std::sort(numList.begin(), numList.end());
    }
    
    double findMedian() {
        if(numList.size() == 1) return numList[0];
        if(numList.size() % 2 == 0) return (numList[(numList.size() / 2)-1] + numList[(numList.size() / 2)])/2.0;
        return numList[numList.size() / 2.0];
    }
};

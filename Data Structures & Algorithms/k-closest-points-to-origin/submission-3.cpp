class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> a, vector<int> b){
            return pow(a[0],2) + pow(a[1], 2) > pow(b[0],2) + pow(b[1], 2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap;
        vector<vector<int>> res;

        for(const vector<int>& point : points){
            minHeap.push(point);
        }

        for(int i = 0; i < k; ++i){
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }
};

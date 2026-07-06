class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> a, vector<int> b){
            return pow(a[0],2)+pow(a[1],2) < pow(b[0],2)+pow(b[1],2);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        for(const vector<int>& point : points){
            maxHeap.push(point);
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return res;
    }
};

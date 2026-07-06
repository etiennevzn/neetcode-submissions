class Solution {
private:
    int computeDistance(const vector<int>& point){
        return (pow(point[0],2) + pow(point[1], 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, vector<int>> a, pair<int, vector<int>> b){
            return a.first > b.first;
        };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> minHeap;
        vector<vector<int>> res;

        for(const vector<int>& point : points){
            minHeap.push({computeDistance(point), point});
        }

        for(int i = 0; i < k; ++i){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};

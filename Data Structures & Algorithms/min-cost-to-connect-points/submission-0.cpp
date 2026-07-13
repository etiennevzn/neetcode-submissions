class Solution {
private:
    int computeDistance(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_set<int> visited;
        int res = 0;
        minHeap.push({0,0});

        while(!minHeap.empty() && visited.size() < points.size()){
            auto [cost, point] = minHeap.top();
            minHeap.pop();
            if(visited.count(point)) continue;
            visited.insert(point);

            res += cost;
            for(int i = 0; i < points.size(); ++i){
                minHeap.push({computeDistance(points[point][0], points[point][1], points[i][0], points[i][1]), i});
            }
        }

        return res;
    }
};

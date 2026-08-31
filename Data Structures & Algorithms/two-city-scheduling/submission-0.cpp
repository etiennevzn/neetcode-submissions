class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> maxHeap;
        int size = costs.size();
        for(int i = 0; i < size; ++i){
            maxHeap.emplace(abs(costs[i][0] - costs[i][1]), i);
        }

        int res = 0;
        int a = 0, b = 0;
        while(!maxHeap.empty()){
            auto [diff, i] = maxHeap.top();
            maxHeap.pop();
            if((costs[i][0] <= costs[i][1] && a < size / 2) || b == size / 2){
                res += costs[i][0];
                a++;
            }else{
                res += costs[i][1];
                b++;
            }
        }

        return res;
    }
};
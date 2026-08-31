class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
            return a[0] - a[1] < b[0] - b[1];
        });

        int res = 0, size = costs.size();
        for(int i = 0; i < size; ++i){
            if(i < size / 2){
                res += costs[i][0];
            }else{
                res += costs[i][1];
            }
        }

        return res;
    }
};
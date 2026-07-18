class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for(int query : queries){
            int smallest = INT_MAX;
            for(const auto& interval : intervals){
                if(interval[0] <= query && interval[1] >= query){
                    smallest = min(smallest, interval[1] - interval[0] + 1);
                }
            }
            smallest = smallest == INT_MAX ? -1 : smallest;
            res.push_back(smallest);
        }

        return res;
    }
};

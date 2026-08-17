class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> locations(1001);

        for(const auto& trip : trips){
            locations[trip[1]] += trip[0];
            locations[trip[2]] -= trip[0];
        }

        int curPassengers = 0;
        for(const auto& loc : locations){
            curPassengers += loc;
            if(curPassengers > capacity) return false;
        }

        return true;
    }
};
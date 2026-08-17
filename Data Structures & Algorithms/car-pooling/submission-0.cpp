class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> passengers;
        for(const auto& trip : trips){
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }

        int numP = 0;
        for(const auto& p : passengers){
            numP += p.second;
            if(numP > capacity) return false;
        }

        return true;
    }
};
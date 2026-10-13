class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> res;
        res.push_back(n - 1);

        for(int i = n - 2; i >= 0; --i){
            if(heights[i] > heights[res.back()]){
                res.push_back(i);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
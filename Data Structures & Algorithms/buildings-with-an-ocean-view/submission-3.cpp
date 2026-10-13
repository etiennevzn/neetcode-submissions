class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int tallest = heights[n - 1];
        vector<int> res;
        res.push_back(n - 1);

        for(int i = n - 2; i >= 0; --i){
            if(heights[i] > tallest){
                res.push_back(i);
                tallest = heights[i];
            }
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};
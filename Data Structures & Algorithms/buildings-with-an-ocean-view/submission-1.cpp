class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> tallestRight(n);
        tallestRight[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i){
            tallestRight[i] = max(tallestRight[i + 1], heights[i + 1]);
        }

        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(heights[i] > tallestRight[i]) res.push_back(i);
        }

        return res;
    }
};
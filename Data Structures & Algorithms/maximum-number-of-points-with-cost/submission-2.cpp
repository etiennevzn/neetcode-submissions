class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int ROWS = points.size(), COLS = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());

        for(int r = 1; r < ROWS; ++r){
            vector<long long> left(COLS), right(COLS);

            left[0] = dp[0];
            for(int c = 1; c < COLS; ++c){
                left[c] = max(dp[c], left[c - 1] - 1);
            }

            right[COLS - 1] = dp[COLS - 1];
            for(int c = COLS - 2; c >= 0; --c){
                right[c] = max(dp[c], right[c + 1] - 1);
            }

            for(int c = 0; c < COLS; ++c) dp[c] = points[r][c] + max(left[c], right[c]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
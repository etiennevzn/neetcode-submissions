class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(0));
        for(int i = 0; i <= n; ++i){
            if(i == n){
                dp[i].resize(triangle[i - 1].size() + 1, 0);
            }else{
                dp[i].resize(triangle[i].size(), 0);
            }
        }

        for(int i = n - 1; i >= 0; --i){
            for(int j = 0; j < dp[i].size(); ++j){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
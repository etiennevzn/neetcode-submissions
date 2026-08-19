class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n, 1));
        for(int target = 1; target <= n; ++target){
            for(int i = 1; i <= n - 1; ++i){
                if(i > target){
                    dp[target][i] = dp[target][target];
                }else{
                    dp[target][i] = max(i * dp[target - i][i], dp[target][i - 1]);
                }
            }
        }
        return dp[n][n - 1];
    }
};
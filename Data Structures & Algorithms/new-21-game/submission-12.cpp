class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k - 1 + maxPts <= n) return 1.0;

        vector<double> dp(k + maxPts, 0);
        dp[k - 1] = (double)(n - k + 1) / maxPts;
        for(int i = k; i <= n; ++i) dp[i] = 1;

        for(int i = k - 2; i >= 0; --i){
            dp[i] = dp[i + 1] - dp[i + 1 + maxPts] / maxPts + dp[i + 1] / maxPts;
        }

        return dp[0];
    }
};
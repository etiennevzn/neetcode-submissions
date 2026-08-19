class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        for(int num = 2; num <= n; ++num){
            int res = (num == n) ? 0 : num;
            for(int i = 1; i < num; ++i){
                res = max(res, dp[i - 1] * dp[num - i - 1]);
            }
            dp[num - 1] = res;
        }
        return dp[n - 1];
    }
};
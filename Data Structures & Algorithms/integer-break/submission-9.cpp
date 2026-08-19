class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int num = 2; num <= n; ++num){
            int res = (num == n) ? 0 : num;
            for(int i = 1; i < num; ++i){
                res = max(res, dp[i] * dp[num - i]);
            }
            dp[num] = res;
        }
        return dp[n];
    }
};
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;

        for(size_t i = 2; i < dp.size(); ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};

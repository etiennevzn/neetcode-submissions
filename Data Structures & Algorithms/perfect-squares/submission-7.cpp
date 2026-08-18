class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for(int target = 1; target <= n; ++target){
            int res = target;
            for(int i = 1; i * i <= target; ++i){
                res = min(res, 1 + dp[target - i * i]);
            }
            dp[target] = res;
        }

        return dp[n];
    }
};
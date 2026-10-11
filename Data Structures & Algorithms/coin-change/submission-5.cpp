class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        for(int i = 0; i <= coins.size(); ++i){
            dp[i][0] = 0;
        }

        for(int i = coins.size() - 1; i >= 0; --i){
            for(int a = 1; a <= amount; ++a){
                int take = INT_MAX;
                if(coins[i] <= a){
                    take = dp[i][a - coins[i]];
                }
                if(take != INT_MAX) take++;
                dp[i][a] = min(take, dp[i + 1][a]);
            }
        }

        int res = dp[0][amount];
        return res == INT_MAX ? -1 : res;
    }
};

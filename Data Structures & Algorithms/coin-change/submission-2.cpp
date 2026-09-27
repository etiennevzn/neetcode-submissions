class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for(int i = 1; i <= amount; ++i){
            int res = INT_MAX;
            for(int coin : coins){
                if(i - coin >= 0){
                    int take = dp[i - coin];
                    if(take != INT_MAX) res = min(res, 1 + take);
                }
            }
            dp[i] = res;
        }
    	
        int res = dp[amount];
        return res == INT_MAX ? -1 : res;
    }
};

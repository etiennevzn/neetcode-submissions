class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);

        for(int a = 1; a <= amount; ++a){
            int res = 100000;
            for(int coin : coins){
                if(coin > a) continue;
                res = min(res, 1 + dp[a - coin]);
            }
            dp[a] = res;
        }

        if(dp[amount] > 10000) return -1;
        return dp[amount];
    }
};

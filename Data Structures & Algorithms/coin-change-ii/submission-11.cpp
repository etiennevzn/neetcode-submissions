class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        vector<int> newDp(amount + 1);
        dp[0] = 1;

        for(int i = n - 1; i >= 0; --i){
            fill(newDp.begin(), newDp.end(), 0);
            newDp[0] = 1;
            for(int a = 1; a <= amount; ++a){
                newDp[a] = dp[a];
                if(coins[i] <= a){
                    newDp[a] += newDp[a - coins[i]];
                }
            }
            dp = newDp;
        }

        return dp[amount];
    }
};

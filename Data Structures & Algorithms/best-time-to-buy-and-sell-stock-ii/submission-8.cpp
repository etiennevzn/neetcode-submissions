class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; --i){
            for(int canBuy = 0; canBuy <= 1; ++canBuy){
                int hold = dp[i + 1][canBuy], buy = 0, sell = 0;
                if(canBuy){
                    buy = -prices[i] + dp[i + 1][0];
                }else{
                    sell = prices[i] + dp[i + 1][1];
                }
                dp[i][canBuy] = max({hold, buy, sell});
            }
        }
        
        return dp[0][1];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int nextCanBuy = 0, nextCanSell = 0;

        for(int i = n - 1; i >= 0; --i){
            int curCanBuy = max(nextCanBuy, -prices[i] + nextCanSell);
            int curCanSell = max(nextCanSell, prices[i] + nextCanBuy);
            nextCanBuy = curCanBuy;
            nextCanSell = curCanSell;
        }
        
        return nextCanBuy;
    }
};
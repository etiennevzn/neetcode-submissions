class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for(const int& sell : prices){
            maxProfit = max(maxProfit, sell-bestBuy);
            bestBuy = min(bestBuy, sell);
        }
        return maxProfit;
    }
};

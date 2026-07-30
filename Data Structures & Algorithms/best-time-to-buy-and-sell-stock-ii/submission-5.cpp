class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextDay(2, 0), curDay(2,0);

        for(int i = n - 1; i >= 0; --i){
            curDay[0] = max(prices[i] + nextDay[1], nextDay[0]);
            curDay[1] = max(-prices[i] + nextDay[0], nextDay[1]); 
            nextDay = curDay;
        }

        return curDay[1];
    }
};
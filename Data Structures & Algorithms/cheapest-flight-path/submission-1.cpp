class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for(int i = 0; i < k+1; ++i){
            vector<int> tempPrices = prices;
            for(const auto& flight : flights){
                int s = flight[0], d = flight[1], price = flight[2];
                if(prices[s] != INT_MAX && tempPrices[d] > prices[s] + price) tempPrices[d] = prices[s] + price;
            }
            prices = tempPrices;
        }

        return  prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

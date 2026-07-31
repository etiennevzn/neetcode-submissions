class StockSpanner {
private:
    vector<int> prices;
public:
    StockSpanner() {}
    
    int next(int price) {
        prices.push_back(price);
        int counter = 0;
        int i = prices.size() - 1;
        while(i >= 0 && prices[i--] <= price){
            counter++;
        }
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
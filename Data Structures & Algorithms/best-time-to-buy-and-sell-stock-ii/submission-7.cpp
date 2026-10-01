class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int canBuy, const vector<int>& prices){
        if(i == prices.size()) return 0;
        if(memo[i][canBuy] != -1) return memo[i][canBuy];

        int buy = 0, sell = 0, hold = 0;
        if(canBuy){
            buy = -prices[i] + dfs(i + 1, 0, prices);
        }else{
            sell = prices[i] + dfs(i + 1, 1, prices);
        }
        hold = dfs(i + 1, canBuy, prices);

        return memo[i][canBuy] = max({buy, sell, hold});
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2, -1));
        return dfs(0, 1, prices);
    }
};
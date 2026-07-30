class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int day, bool canBuy, vector<int>& prices){
        if(day == prices.size()) return 0;
        if(memo[day][static_cast<int>(canBuy)] != -1) return memo[day][static_cast<int>(canBuy)];

        int res = dfs(day + 1, canBuy, prices);
        if(canBuy){
            return memo[day][static_cast<int>(canBuy)] = max(-prices[day] + dfs(day + 1, false, prices), res);
        }else{
            return memo[day][static_cast<int>(canBuy)] = max(prices[day] + dfs(day + 1, true, prices), res);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices);
    }
};
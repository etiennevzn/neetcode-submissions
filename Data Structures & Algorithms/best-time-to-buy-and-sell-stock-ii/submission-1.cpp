class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int day, bool canBuy, vector<int>& prices){
        if(day >= prices.size()) return 0;
        if(memo[day][static_cast<int>(canBuy)] != -1) return memo[day][static_cast<int>(canBuy)];

        if(canBuy){
            return memo[day][static_cast<int>(canBuy)] = max(-prices[day] + dfs(day + 1, false, prices), dfs(day + 1, true, prices));
        }else{
            return memo[day][static_cast<int>(canBuy)] = max(prices[day] + dfs(day + 1, true, prices), dfs(day + 1, false, prices));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices);
    }
};
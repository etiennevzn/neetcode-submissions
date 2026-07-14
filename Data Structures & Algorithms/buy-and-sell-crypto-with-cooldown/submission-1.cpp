class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, bool canBuy, vector<int>& prices){
        if(i >= prices.size()) return 0;
        if(memo[i][canBuy] != -1) return memo[i][canBuy];

        if(canBuy){
            memo[i][canBuy]  = max(-prices[i] + dfs(i+1, false, prices), dfs(i+1, true, prices));
        }else{
            memo[i][canBuy] =  max(prices[i] + dfs(i+2, true, prices), dfs(i+1, false, prices));
        }

        return memo[i][canBuy];
    }
public:
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices);
    }
};

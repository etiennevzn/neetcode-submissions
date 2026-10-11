class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, const vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(i == coins.size() || amount < 0) return INT_MAX;
        if(memo[i][amount] != -1) return memo[i][amount];

        int take = dfs(i, coins, amount - coins[i]);
        if(take != INT_MAX) take = 1 + take;
        int skip = dfs(i + 1, coins, amount);

        return memo[i][amount] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(coins.size(), vector<int>(amount + 1, -1));
        int res = dfs(0, coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
private:
    vector<int> memo;
    int dfs(int amount, const vector<int>& coins){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(memo[amount] != -1) return memo[amount];

        int res = INT_MAX;
        for(int i = 0; i < coins.size(); ++i){
            int take = dfs(amount - coins[i], coins);
            if(take != INT_MAX) res = min(res, 1 + take);
        }

        return memo[amount] = res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1, -1);
        int res = dfs(amount, coins);
        return res == INT_MAX ? -1 : res;
    }
};

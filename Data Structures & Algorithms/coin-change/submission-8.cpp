class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int idx, int amount, const vector<int>& coins){
        if(amount == 0) return 0;
        if(idx == coins.size() || amount < 0) return 100000;
        if(memo[idx][amount] != -1) return memo[idx][amount];

        return memo[idx][amount] = min(1 + dfs(idx, amount - coins[idx], coins), dfs(idx + 1, amount, coins));
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(coins.size(), vector<int>(amount + 1, -1));
        int res = dfs(0, amount, coins);
        if(res > 10000) return -1;
        return res;
    }
};

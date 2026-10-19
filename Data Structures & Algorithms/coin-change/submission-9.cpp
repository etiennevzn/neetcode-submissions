class Solution {
private:
    vector<int> memo;
    int dfs(int amount, const vector<int>& coins){
        if(amount == 0) return 0;
        if(amount < 0) return 100000;
        if(memo[amount] != -1) return memo[amount];

        int res = 100000;
        for(int coin : coins){
            res = min(res, 1 + dfs(amount - coin, coins));
        }

        return memo[amount] = res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -1);
        int res = dfs(amount, coins);
        if(res > 10000) return -1;
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, int target, vector<int>& coins){
        if(target == 0){
            return 1;
        }
        if(memo[i][target] != -1) return memo[i][target];

        memo[i][target] = 0;
        for(size_t j = i; j < coins.size(); ++j){
            int newT = target - coins[j];
            if(newT >= 0){
                memo[j][newT] = dfs(j, newT, coins);
                memo[i][target] += memo[j][newT];
            }
        }

        return memo[i][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }
};

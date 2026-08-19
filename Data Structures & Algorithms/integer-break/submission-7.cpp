class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, int target){
        if(target == 0 || i == 0) return 1;
        if(memo[target][i] != -1) return memo[target][i];
        if(i > target) return memo[target][i] = dfs(target, target);

        return memo[target][i] = max(i * dfs(i, target - i), dfs(i - 1, target));
    }
public:
    int integerBreak(int n) {
        memo.resize(n + 1, vector<int>(n, -1));
        return dfs(n - 1, n);
    }
};
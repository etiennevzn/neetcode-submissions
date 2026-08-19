class Solution {
private:
    vector<int> memo;

    int dfs(int i, int target){
        if(target == 0 || i == 0) return 1;
        if(i > target) return dfs(target, target);
        if(memo[target] != -1) return memo[target];

        return memo[target] = max(i * dfs(i, target - i), dfs(i - 1, target));
    }
public:
    int integerBreak(int n) {
        memo.resize(n + 1, -1);
        return dfs(n - 1, n);
    }
};
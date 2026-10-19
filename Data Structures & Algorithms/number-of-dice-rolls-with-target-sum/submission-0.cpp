class Solution {
private:
    int cnt = 0;
    int MOD = 1e9 + 7;
    
    vector<vector<int>> memo;
    int dfs(int k, int n, int target){
        if(target == 0 && n == 0) return 1;
        if(n == 0 || target == 0) return 0;
        if(memo[n][target] != -1) return memo[n][target];

        int res = 0;
        for(int i = 1; i <= k && i <= target; ++i){
            res = (res + dfs(k, n - 1, target - i)) % MOD;
        }

        return memo[n][target] = res;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memo.assign(n + 1, vector<int>(target + 1, -1));
        return dfs(k, n, target);
    }
};

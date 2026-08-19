class Solution {
private:
    vector<int> memo;

    int dfs(int target, int k){
        if(target == 0) return k >= 2;
        if(memo[target] != -1) return memo[target];

        int res = 1;
        for(int num = 1; num <= target; ++num){
            res = max(res, num * dfs(target - num, k + 1));
        }
        return memo[target] = res;
    }
public:
    int integerBreak(int n) {
        memo.resize(n + 1, -1);
        return dfs(n, 0);
    }
};
class Solution {
private:
    vector<int> memo;
    int dfs(int target){
        if(target == 0) return 0;
        if(memo[target] != -1) return memo[target];

        int res = target;
        for(int i = 1; i * i <= target; ++i){
            res = min(res, 1 + dfs(target - i * i));
        }
        return memo[target] = res;
    }
public:
    int numSquares(int n) {
        memo.resize(n + 1, -1);
        return dfs(n);
    }
};
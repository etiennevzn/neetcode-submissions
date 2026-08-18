class Solution {
private:
    vector<int> memo;
    int dfs(int target, int limit){
        if(target == 0) return 0;
        if(target < 0) return limit;

        if(memo[target] != -1) return memo[target];

        int res = target;
        for(int i = 1; i < limit; ++i){
            res = min(res, 1 + dfs(target - (i * i), limit));
        }
        return memo[target] = res;
    }
public:
    int numSquares(int n) {
        int i = 1;
        while(true){
            if(i * i == n) return 1;
            if(i * i > n) break;
            i++;
        }

        memo.resize(n + 1, -1);
        return dfs(n, i);
    }
};
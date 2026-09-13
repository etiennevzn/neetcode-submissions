class Solution {
private:
    int total = 0, good = 0;
    vector<double> memo;

    double dfs(int cur, int n, int k, int maxPts){
        if(cur >= k){
            return cur <= n ? 1.0 : 0.0;
        }
        if(memo[cur] != -1.0) return memo[cur];

        double res = 0;
        for(int i = 1; i <= maxPts; ++i){
            res += dfs(cur + i, n, k, maxPts);
        }
        return memo[cur] = res / maxPts;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        memo.resize(k, -1.0);
        return dfs(0, n, k, maxPts);
    }
};
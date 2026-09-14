class Solution {
private:
    int total = 0, good = 0;
    vector<double> memo;

    double dfs(int cur, int n, int k, int maxPts){
        if(cur == k - 1){
            return min(n - k + 1, maxPts) / (double)maxPts;
        }

        if(cur >= k){
            return cur <= n ? 1.0 : 0.0;
        }
        if(memo[cur] != -1.0) return memo[cur];

        memo[cur] = dfs(cur+1, n, k, maxPts);
        memo[cur] += (dfs(cur+1, n, k, maxPts) - dfs(cur + 1 + maxPts, n, k, maxPts)) / maxPts;
        return memo[cur];
    }
public:
    double new21Game(int n, int k, int maxPts) {
        memo.resize(k + maxPts, -1.0);
        return dfs(0, n, k, maxPts);
    }
};
class Solution {
private:
    vector<double> memo;
    double dfs(int pts, int n, int k, int maxPts){
        if(pts == k - 1) return (double)min(n - k + 1, maxPts) / maxPts;
        if(pts >= k && pts <= n) return 1;
        if(pts > n) return 0;
        if(memo[pts] != -1) return memo[pts];

        double next = dfs(pts + 1, n, k, maxPts);
        return memo[pts] = next - dfs(pts + maxPts + 1, n, k, maxPts) / maxPts + next / maxPts;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        memo.assign(k, -1);
        return dfs(0, n, k, maxPts);
    }
};
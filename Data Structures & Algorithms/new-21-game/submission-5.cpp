class Solution {
private:
    vector<double> memo;
    double dfs(int pts, int n, int k, int maxPts){
        if(pts >= k && pts <= n) return 1;
        if(pts > n) return 0;
        if(memo[pts] != -1) return memo[pts];

        double cnt = 0;
        for(int i = 1; i <= maxPts; ++i){
            cnt += dfs(pts + i, n, k, maxPts);
        }

        return memo[pts] = cnt / maxPts;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        memo.assign(k, -1);
        return dfs(0, n, k, maxPts);
    }
};
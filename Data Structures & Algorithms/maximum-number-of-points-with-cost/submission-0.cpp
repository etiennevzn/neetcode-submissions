class Solution {
private:
    vector<vector<long long>> memo;
    long long dfs(int r, int pc, const vector<vector<int>>& points){
        if(r == points.size()) return 0;
        if(memo[r][pc + 1] != -1) return memo[r][pc + 1];

        long long res = 0;
        for(int c = 0; c < points[0].size(); ++c){
            int sub = pc == -1 ? 0 : abs(pc - c); 
            res = max(res, points[r][c] - sub + dfs(r + 1, c, points));
        }
        return memo[r][pc + 1] = res;
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        memo.resize(points.size(), vector<long long>(points[0].size() + 1, -1));
        return dfs(0, -1, points);
    }
};
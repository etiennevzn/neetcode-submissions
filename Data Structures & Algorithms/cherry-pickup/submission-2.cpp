class Solution {
private:
    int N;
    vector<vector<vector<int>>> memo;

    int dfs(int r1, int c1, int r2, const vector<vector<int>>& grid){
        int c2 = r1 + c1 - r2;
        if(r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
        if(r1 == N - 1 && c1 == N - 1) return grid[r1][c1];
        
        if(memo[r1][c1][r2] != INT_MIN) return memo[r1][c1][r2];

        int cherries = grid[r1][c1];
        if(r1 != r2 || c1 != c2) cherries += grid[r2][c2];

        int p1 = dfs(r1 + 1, c1, r2 + 1, grid);
        int p2 = dfs(r1 + 1, c1, r2, grid);
        int p3 = dfs(r1, c1 + 1, r2 + 1, grid);
        int p4 = dfs(r1, c1 + 1, r2, grid);
        int best = max({p1, p2, p3, p4});
        if(best == INT_MIN) return memo[r1][c1][r2] = best;

        return memo[r1][c1][r2] = cherries + best;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        memo.resize(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));

        int res = dfs(0, 0, 0, grid); 
        return res == INT_MIN ? 0 : res;
    }
};
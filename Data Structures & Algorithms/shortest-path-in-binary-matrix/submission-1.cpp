class Solution {
private:
    int n;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    vector<vector<int>> memo;
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 1) return INT_MAX;
        if(r == n - 1 && c == n - 1) return 1;
        if(memo[r][c] != -1) return memo[r][c];

        int path = INT_MAX;
        grid[r][c] = 1;
        for(const auto& dir : dirs){
            int nr = r + dir.first, nc = c + dir.second;
            path = min(path, dfs(nr, nc, grid));
        }
        grid[r][c] = 0;

        return memo[r][c] = path == INT_MAX ? path : 1 + path;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        memo.resize(n, vector<int>(n, -1));
        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        int res = dfs(0, 0, grid);
        return res == INT_MAX ? -1 : res;
    }
};
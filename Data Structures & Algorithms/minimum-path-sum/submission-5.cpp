class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> memo;
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r == ROWS - 1 && c == COLS - 1) return grid[r][c];
        if(r >= ROWS || c >= COLS) return INT_MAX;

        if(memo[r][c] != -1) return memo[r][c];
        return memo[r][c] = grid[r][c] + min(dfs(r + 1, c, grid), dfs(r, c + 1, grid));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        memo.resize(ROWS, vector<int>(COLS, -1));
        return dfs(0, 0, grid);
    }
};
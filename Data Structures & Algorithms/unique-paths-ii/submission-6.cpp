class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> memo;
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r == ROWS || c == COLS || grid[r][c] == 1) return 0;
        if(r == ROWS - 1 && c == COLS - 1) return 1;

        if(memo[r][c] != -1) return memo[r][c];
        return memo[r][c] = dfs(r + 1, c, grid) + dfs(r, c + 1, grid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ROWS = obstacleGrid.size();
        COLS = obstacleGrid[0].size();
        memo.resize(ROWS, vector<int>(COLS, -1));
        return dfs(0, 0, obstacleGrid);
    }
};
class Solution {
private:
    int COLS, ROWS;
    vector<vector<int>> memo;
    int dfs(int r, int c, vector<vector<int>>& obstacleGrid){
        if(r == ROWS - 1 && c == COLS - 1) return 1;
        if(r == ROWS || c == COLS || obstacleGrid[r][c] == 1) return 0;
        if(memo[r][c] != -1) return memo[r][c];

        return memo[r][c] = dfs(r + 1, c, obstacleGrid) + dfs(r, c + 1, obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ROWS = obstacleGrid.size();
        COLS = obstacleGrid[0].size();
        if(obstacleGrid[ROWS - 1][COLS - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        memo.assign(ROWS, vector<int>(COLS, -1));
        return dfs(0,0,obstacleGrid);
    }
};
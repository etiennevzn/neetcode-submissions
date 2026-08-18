class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[ROWS - 1][COLS - 1]) return 0;

        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, 0));
        dp[ROWS - 1][COLS - 1] = 1;

        for(int r = ROWS - 1; r >= 0; --r){
            for(int c = COLS - 1; c >= 0; --c){
                if(r == ROWS - 1 && c == COLS - 1) continue;
                if(obstacleGrid[r][c] == 1){
                    dp[r][c] = 0;
                }else{
                    dp[r][c] = dp[r + 1][c] + dp[r][c + 1];
                }
            }
        }

        return dp[0][0];
    }
};
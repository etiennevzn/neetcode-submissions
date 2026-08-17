class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<int> dp(COLS + 1, INT_MAX);
        dp[COLS - 1] = grid[ROWS - 1][COLS - 1];

        for(int r = ROWS - 1; r >= 0; --r){
            for(int c = COLS - 1; c >= 0; --c){
                if(r == ROWS - 1 && c == COLS - 1) continue;
                dp[c] = grid[r][c] + min(dp[c], dp[c + 1]);
            }
        }
        
        return dp[0];
    }
};
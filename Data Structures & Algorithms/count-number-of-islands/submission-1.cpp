class Solution {
private:
    int ROWS;
    int COLS;
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != '1') return;
        grid[r][c] = '0';

        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == '1'){
                    res++;
                    dfs(grid, r, c);
                }
            }
        }

        return res;
    }
};

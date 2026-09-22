class Solution {
private:
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<int>>& grid){
        if(r >= ROWS || c >= COLS || r < 0 || c < 0 || grid[r][c] != 1) return;
    
        grid[r][c] = -1;
        for(const auto& dir : dirs){
            int nr = r + dir.first, nc = c + dir.second; 
            dfs(nr, nc, grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1){
                    dfs(r, c, grid);
                }
            }
        }

        int res = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1) res++;
            }
        }

        return res;
    }
};
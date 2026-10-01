class Solution {
private:
    int ROWS, COLS;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '0';
        for(const auto& dir : dirs){
            int nr = r + dir.first, nc = c + dir.second;
            if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == '1'){
                dfs(nr, nc, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int res = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == '1'){
                    res++;
                    dfs(r, c, grid);
                }
            }
        }

        return res;
    }
};

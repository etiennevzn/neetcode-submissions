class Solution {
private:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int ROWS, COLS;
    int dfs(int r, int c, vector<vector<int>>& grid){
        grid[r][c] = -1;
        int perimeter = 0;
        for(const auto& dir : dirs){
            int nr = r + dir.first, nc = c + dir.second;
            if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS){
                if(!grid[nr][nc]){
                    perimeter++;
                }else if(grid[nr][nc] == 1){
                    perimeter += dfs(nr, nc, grid);
                }
            }else{
                perimeter++;
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c]) return dfs(r, c, grid);
            }
        }
        return 0;
    }
};
class Solution {
private:
    int ROWS = 0, COLS = 0;
    vector<pair<int,int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0') return;
        grid[r][c] = '0';
        for(const auto& dir : directions){
            dfs(r+dir.first, c+dir.second, grid);
        }
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
                    dfs(r, c, grid);
                }
            }
        }

        return res;
    }
};

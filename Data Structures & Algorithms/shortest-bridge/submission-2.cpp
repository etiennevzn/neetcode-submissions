class Solution {
private:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int ROWS, COLS;

    void markIsland(int r, int c, vector<vector<int>>& grid){
        if(r >= ROWS || r < 0 || c >= COLS || c < 0 || grid[r][c] != 1) return;
        grid[r][c] = -1;
        for(const pair<int,int>& dir : dirs) markIsland(r + dir.first, c + dir.second, grid);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        bool found = false;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    markIsland(r, c, grid);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int,int>> q;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == -1){
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }

        int res = 0;
        while(!q.empty()){
            for(int i = q.size(); i > 0; --i){
                auto [r, c] = q.front();
                q.pop();
                if(grid[r][c] == 1) return res - 1;
                for(const pair<int,int>& dir : dirs){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr >= ROWS || nr < 0 || nc >= COLS || nc < 0 || visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
            res++;
        }

        return res;
    }
};
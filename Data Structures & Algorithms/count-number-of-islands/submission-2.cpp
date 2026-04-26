class Solution {
private:
    int ROWS;
    int COLS;
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r,c+1});
        q.push({r,c-1});
        q.push({r+1,c});
        q.push({r-1,c});

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int nr = cur.first;
            int nc = cur.second;

            if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] == '0') continue;

            grid[nr][nc] = '0';
            q.push({nr,nc+1});
            q.push({nr,nc-1});
            q.push({nr+1,nc});
            q.push({nr-1,nc});
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
                    bfs(grid, r, c);
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;

        bool found = false;
        for(int r = 0; r < ROWS; ++r){
            if(found) break;
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c]){
                    q.push({r,c});
                    grid[r][c] = -1;
                    found = true;
                    break;
                }
            }
        }
        
        int perimeter = 0;
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(const auto& dir : dirs){
                int nr = r + dir.first, nc = c + dir.second;
                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS){
                    if(!grid[nr][nc]){
                        perimeter++;
                    }else if(grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = -1;
                    }
                }else{
                    perimeter++;
                }
            }
        }

        return perimeter;
    }
};
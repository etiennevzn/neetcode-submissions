class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int numOranges = 0;

        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int,int>> rotted;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c]) numOranges++;
                if(grid[r][c] == 2){
                    rotted.emplace(r, c);
                }
            }
        }

        if(rotted.size() == numOranges) return 0;

        int minutes = 0;
        while(!rotted.empty()){
            for(int i = rotted.size(); i > 0; --i){
                auto [r, c] = rotted.front();
                rotted.pop();
                for(const auto& dir : dirs){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    rotted.emplace(nr, nc);
                }
            }
            minutes++;
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1) return -1;
            }
        }

        return minutes - 1;
    }
};
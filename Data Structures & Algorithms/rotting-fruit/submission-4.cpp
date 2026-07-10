class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ROWS = grid.size(), COLS = grid[0].size();
        int time = 0;
        int fresh = 0;

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0, -1}};

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 2) q.push({r,c});
                if(grid[r][c] == 1) fresh++;
            }
        }
        
        while(!q.empty() && fresh > 0){
            int qLen = q.size();

            for(int i = 0; i < qLen; ++i){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(const auto& dir : directions){
                    int newr = r + dir.first;
                    int newc = c + dir.second;
                    if(newr < 0 || newr >= ROWS || newc < 0 || newc >= COLS || grid[newr][newc] != 1) continue;

                    grid[newr][newc] = 2;
                    fresh--;
                    q.push({newr, newc});
                }
            }
            time++;
        }

        return fresh > 0 ? -1 : time;
    }
};

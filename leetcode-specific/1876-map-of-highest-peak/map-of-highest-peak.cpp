class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int ROWS = isWater.size(), COLS = isWater[0].size();
        vector<vector<int>> heights(ROWS, vector<int>(COLS, -1));
        queue<pair<int,int>> cells;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(isWater[r][c] == 1){
                    heights[r][c] = 0;
                    cells.emplace(r, c);
                }
            }
        }

        int curHeight = 0;
        while(!cells.empty()){
            for(int i = cells.size(); i > 0; --i){
                auto [r, c] = cells.front();
                cells.pop();

                for(const auto& [dr, dc] : dirs){
                    int nr = r + dr, nc = c + dc;
                    if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || heights[nr][nc] != -1) continue;
                    heights[nr][nc] = curHeight + 1;
                    cells.emplace(nr, nc);
                }
            }

            curHeight++;
        }

        return heights;
    }
};
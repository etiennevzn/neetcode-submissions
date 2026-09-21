class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> rCount(ROWS), cCount(COLS);

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    rCount[r]++;
                    cCount[c]++;
                }
            }
        }

        int res = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    if(max(rCount[r], cCount[c]) > 1) res++;
                }
            }
        }

        return res;
    }
};
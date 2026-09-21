class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        unordered_set<int> servers;

        for(int r = 0; r < ROWS; ++r){
            int countR = 0, awaiting = 0;
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    countR++;
                    if(countR == 1) awaiting = COLS * r + c;
                    if(countR >= 2){
                        if(countR == 2) servers.insert(awaiting);
                        servers.insert(COLS * r + c);
                    }
                }
            }
        }

        for(int c = 0; c < COLS; ++c){
            int countC = 0, awaiting = 0;
            for(int r = 0; r < ROWS; ++r){
                if(grid[r][c] == 1){
                    countC++;
                    if(countC == 1) awaiting = COLS * r + c;
                    if(countC >= 2){
                        if(countC == 2) servers.insert(awaiting);
                        servers.insert(COLS * r + c);
                    }
                }
            }
        }

        return servers.size();
    }
};
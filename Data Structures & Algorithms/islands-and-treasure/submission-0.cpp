class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};


        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 0) q.push({r,c});
            }
        }

        while(!q.empty()){
            int qLen = q.size();

            for(int i = 0; i < qLen; ++i){
                pair<int,int> cur = q.front();
                q.pop();
                
                int r = cur.first;
                int c = cur.second;
                for(const auto& dir : directions){
                    int newr = r+dir.first;
                    int newc = c+dir.second;
                    if(newr >= 0 && newr < ROWS && newc >= 0 && newc < COLS && grid[newr][newc] == 2147483647){
                        grid[newr][newc] = grid[r][c] + 1;
                        q.push({newr, newc});
                    } 
                }
            }
        }
    }
};

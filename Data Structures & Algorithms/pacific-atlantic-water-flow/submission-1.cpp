class Solution {
private:
    int ROWS;
    int COLS;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        if (ocean[r][c]) return;

        ocean[r][c] = true;

        for(auto [dr,dc] : directions){
            int nr = r+dr;
            int nc = c+dc;

            if(nr>=0 && nr<ROWS && nc>=0 && nc<COLS && heights[nr][nc] >= heights[r][c]){
                dfs(heights, ocean, nr, nc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; ++r){
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, COLS-1);
        }

        for(int c = 0; c < COLS; ++c){
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, ROWS-1, c);
        }
        
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(pacific[r][c] && atlantic[r][c]) res.push_back({r,c});
            }
        }

        return res;
    }
};

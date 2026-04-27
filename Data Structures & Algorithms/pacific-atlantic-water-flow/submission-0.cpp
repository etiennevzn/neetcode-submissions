class Solution {
private:
    int ROWS;
    int COLS;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        if (ocean[r][c]) return;

        ocean[r][c] = true;
        if(c+1 < COLS){
            if(heights[r][c+1] >= heights[r][c]) dfs(heights, ocean, r, c+1);
        }

        if(c - 1 >= 0){
            if(heights[r][c-1] >= heights[r][c]) dfs(heights, ocean, r, c-1);
        }

        if(r+1 < ROWS){
            if(heights[r+1][c] >= heights[r][c]) dfs(heights, ocean, r+1, c);
        }

        if(r-1 >= 0){
            if(heights[r-1][c] >= heights[r][c]) dfs(heights, ocean, r-1, c);
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
        }

        for(int r = 0; r < ROWS; ++r){
            dfs(heights, atlantic, r, COLS-1);
        }

        for(int c = 0; c < COLS; ++c){
            dfs(heights, pacific, 0, c);
        }

        for(int c = 0; c < COLS; ++c){
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

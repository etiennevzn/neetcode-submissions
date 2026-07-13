class Solution {
private:
    int DIM;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int t = 0;
    set<pair<int,int>> visited;

    bool dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r >= DIM || c < 0 || c >= DIM || grid[r][c] > t) return false;
        if(r == DIM - 1 && c == DIM - 1) return true;

        visited.insert({r,c});
        for(const auto& dir : directions){
            int newr = r + dir[0], newc = c + dir[1];
            if(!visited.count({newr, newc})){
                if(dfs(newr, newc, grid)) return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        DIM = grid.size();
        for(t = 0; t < 2500; ++t){
            visited.clear();
            if(dfs(0,0,grid)) return t;
        }
        return t;
    }
};

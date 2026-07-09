class Solution {
private:
    int maxArea = 0;
    vector<pair<int,int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) return 0;
        grid[r][c] = -1;

        int area = 1;
        for(const auto& dir : directions){
            area += dfs(r + dir.first, c + dir.second, grid);
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(size_t r = 0; r < grid.size(); ++r){
            for(size_t c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == 1)  maxArea = max(maxArea, dfs(r, c, grid));
            }
        }
        return maxArea;
    }
};

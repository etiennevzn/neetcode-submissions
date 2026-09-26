class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int pathLength = 1;

        while(!q.empty()){
            for(int i = q.size(); i > 0; --i){
                auto [r, c] = q.front();
                q.pop();

                if(r == n - 1 && c == n - 1) return pathLength;

                for(const auto& dir : dirs){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc] && grid[nr][nc] == 0){
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            pathLength++;
        }
        
        return -1;
    }
};
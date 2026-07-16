class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                for(const auto& dir : directions){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && matrix[nr][nc] > matrix[r][c]){
                        indegree[nr][nc]++;
                    }
                }
            }
        }

        queue<pair<int,int>> q;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(!indegree[r][c]) q.push({r,c});
            }
        }

        int res = 0;
        while(!q.empty()){
            res++;
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                auto [r, c] = q.front();
                q.pop();
                for(const auto& dir : directions){
                    int nr = r + dir.first, nc = c + dir.second;
                    if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && matrix[nr][nc] > matrix[r][c]){
                        if(--indegree[nr][nc] == 0) q.push({nr, nc});
                    }
                }
            }
        }
        
        return res;
    }
};

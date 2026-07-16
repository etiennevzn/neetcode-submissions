class Solution {
private:
    vector<pair<int,int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int ROWS, COLS;
    vector<vector<int>> memo;

    int dfs(int r, int c, vector<vector<int>>& matrix){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || matrix[r][c] == -1) return 0;
        if(memo[r][c] != -1) return memo[r][c];

        int tmp = matrix[r][c];
        matrix[r][c] = -1;
        memo[r][c] = 1;
        int maxPath = 0;
        for(const auto& dir : directions){
            int newr = r + dir.first, newc = c + dir.second;
            if(newr < 0 || newr >= ROWS || newc < 0 || newc >= COLS || matrix[newr][newc] == -1) continue;
            if(matrix[newr][newc] > tmp){
                maxPath = max(maxPath, dfs(newr, newc, matrix));
            }
        }
        memo[r][c] += maxPath;
        matrix[r][c] = tmp;
        return memo[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        memo.resize(ROWS, vector<int>(COLS, -1));
        int res;

        for(int i = 0; i < ROWS; ++i){
            for(int j = 0; j < COLS; j++){
                res = max(res, dfs(i, j, matrix));
            }
        }
        
        return res;
    }
};

class Solution {
private: 
    int ROWS, COLS;
    vector<vector<int>> memo;
    int dfs(int r, int c, const vector<vector<char>>& matrix){
        if(r >= ROWS || c >= COLS || matrix[r][c] == '0') return 0;
        if(memo[r][c] != -1) return memo[r][c];

        return memo[r][c] = 1 + min(dfs(r + 1, c + 1, matrix), min(dfs(r + 1, c, matrix), dfs(r, c + 1, matrix)));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ROWS = matrix.size(), COLS = matrix[0].size();
        memo.resize(ROWS, vector<int>(COLS, -1));

        int res = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                res = max(res, dfs(r, c, matrix));
            }
        }

        return res * res;
    }
};
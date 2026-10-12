class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> memo;
    int dfs(int r, int c, const vector<vector<int>>& triangle){
        if(r == ROWS - 1) return triangle[r][c];
        if(memo[r][c] != INT_MAX) return memo[r][c];

        return memo[r][c] = triangle[r][c] + min(dfs(r + 1, c, triangle), dfs(r + 1, c + 1, triangle));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ROWS = triangle.size();
        COLS = triangle[ROWS - 1].size();
        memo.assign(ROWS - 1, vector<int>(COLS - 1, INT_MAX));
        return dfs(0, 0, triangle);
    }
};
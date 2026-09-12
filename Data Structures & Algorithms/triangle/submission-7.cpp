class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int j, const vector<vector<int>>& triangle){
        if(i == triangle.size()) return 0;
        if(memo[i][j] != INT_MAX) return memo[i][j];

        return memo[i][j] = triangle[i][j] + min(dfs(i + 1, j, triangle), dfs(i + 1, j + 1, triangle));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memo.resize(triangle.size());
        for (int i = 0; i < triangle.size(); ++i) memo[i].resize(triangle[i].size(), INT_MAX);

        return dfs(0, 0, triangle);
    }
};
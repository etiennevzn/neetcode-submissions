class Solution {
private:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> count;

    int dfs(int i, const vector<string>& strs, int m, int n){
        if(i == strs.size() || (m == 0 && n == 0)) return 0;
        if(memo[i][m][n] != -1) return memo[i][m][n];

        int skip = dfs(i + 1, strs, m, n);

        int take = 0;
        if(count[i][0] <= m && count[i][1] <= n){
            take = 1 + dfs(i + 1, strs, m - count[i][0], n - count[i][1]);
        }

        return memo[i][m][n] = max(skip, take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        count.resize(strs.size(), vector<int>(2));
        for(int i = 0; i < strs.size(); ++i){
            for(const char& c : strs[i]){
                count[i][c - '0']++;
            }
        }

        memo.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, strs, m, n);
    }
};
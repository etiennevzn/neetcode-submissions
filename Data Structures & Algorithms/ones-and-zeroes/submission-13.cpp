class Solution {
private:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> arr;

    int dfs(int i, const vector<string>& strs, int m, int n){
        if((m == 0 && n == 0) || i == strs.size()) return 0;
        if(memo[i][m][n] != -1) return memo[i][m][n];

        int res = 0;
        if(arr[i][0] <= m && arr[i][1] <= n){
            res = 1 + dfs(i + 1, strs, m - arr[i][0], n - arr[i][1]);
        }

        res = max(res, dfs(i + 1, strs, m, n));
        return memo[i][m][n] = res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        arr.assign(strs.size(), vector<int>(2, 0));
        for(int i = 0; i < strs.size(); ++i){
            for(const char& c : strs[i]){
                arr[i][c - '0']++;
            }
        }

        return dfs(0, strs, m, n);
    }
};
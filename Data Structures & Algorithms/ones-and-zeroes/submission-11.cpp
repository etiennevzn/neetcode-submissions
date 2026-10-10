class Solution {
private:
    vector<vector<vector<int>>> memo;
    int dfs(int i, const vector<string>& strs, int m, int n){
        if((m == 0 && n == 0) || i == strs.size()) return 0;
        if(memo[i][m][n] != -1) return memo[i][m][n];

        int numZ = 0, numO = 0;
        for(const char& c : strs[i]){
            if(c == '0') numZ++;
            if(c == '1') numO++;
        }

        int res = 0;
        if(numZ <= m && numO <= n){
            res = 1 + dfs(i + 1, strs, m - numZ, n - numO);
        }

        res = max(res, dfs(i + 1, strs, m, n));
        return memo[i][m][n] = res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, strs, m, n);
    }
};
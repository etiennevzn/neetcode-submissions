class Solution {
private:
    vector<vector<vector<int>>> memo;
    int dfs(int i, const vector<string>& strs, int m, int n){
        if(i == strs.size() || (m == 0 && n == 0)) return 0;
        if(memo[i][m][n] != -1) return memo[i][m][n];

        int skip = dfs(i + 1, strs, m, n);

        int num0 = 0, num1 = 0;
        for(const char& c : strs[i]){
            if(c == '0') num0++;
            if(c == '1') num1++;
        }

        int take = 0;
        if(num0 <= m && num1 <= n){
            take = 1 + dfs(i + 1, strs, m - num0, n - num1);
        }

        return memo[i][m][n] = max(skip, take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, strs, m, n);
    }
};
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>> count(k, vector<int>(2));
        for(int i = 0; i < k; ++i){
            for(const char& c : strs[i]){
                count[i][c - '0']++;
            }
        }

        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = k - 1; i >= 0; --i){
            for(int j = 0; j <= m; ++j){
                for(int l = 0; l <= n; ++l){
                    int skip = dp[i + 1][j][l];

                    int take = 0;
                    if(count[i][0] <= j && count[i][1] <= l){
                        take = 1 + dp[i + 1][j - count[i][0]][l - count[i][1]];
                    }

                    dp[i][j][l] = max(skip, take);
                }
            }
        }

        return dp[0][m][n];
    }
};
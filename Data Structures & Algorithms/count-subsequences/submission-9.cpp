class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m + 1; ++i){
            dp[i][n] = 1;
        }

        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                int res = dp[i+1][j];
                if(s[i] == t[j]) res += dp[i+1][j+1];
                dp[i][j] = res;
            }
        }
        
        return dp[0][0];
    }
};

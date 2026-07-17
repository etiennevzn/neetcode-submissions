class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m][n] = 1;

        for(int i = m; i >= 0; --i){
            for(int j = n - 1; j >=0; --j){
                if(i == m){
                    if(j + 1 < n && p[j + 1] == '*'){
                        dp[i][j] = dp[i][j + 2];
                    }else{
                        dp[i][j] = 0;
                    }
                    continue;
                }

                bool res = false;

                if(s[i] == p[j] || p[j] == '.'){
                    if(j + 1 < p.size() && p[j + 1] == '*'){
                        res = dp[i][j + 2] || dp[i + 1][j + 2] || dp[i + 1][j];
                    }else{
                        res = dp[i + 1][j + 1];
                    }
                }else{
                    if(j + 1 < p.size() && p[j + 1] == '*') res = dp[i][j + 2];
                }

                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
};

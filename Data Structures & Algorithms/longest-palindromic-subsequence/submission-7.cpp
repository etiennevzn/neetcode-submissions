class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int l = n - 1; l >= 0; --l){
            for(int r = l; r < n; ++r){
                if(r == l){
                    dp[l][r] = 1;
                }else{
                    if(s[l] == s[r]){
                        dp[l][r] = 2 + dp[l + 1][r - 1];
                    }else{
                        dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
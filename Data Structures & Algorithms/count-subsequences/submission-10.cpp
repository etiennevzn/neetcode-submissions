class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = m - 1; i >= 0; --i){
            vector<int> nextDp(n + 1);
            nextDp[n] = 1;
            for(int j = n - 1; j >= 0; --j){
                int res = dp[j];
                if(s[i] == t[j]) res += dp[j+1];
                nextDp[j] = res;
            }
            dp = nextDp;
        }
        
        return dp[0];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> dp(n + 1);
        dp[n] = 1;

        vector<int> nextDp(n + 1, 0);
        for(int i = m; i >= 0; --i){
            fill(nextDp.begin(), nextDp.end(), 0);
            nextDp[n] = (i == m);
            for(int j = n - 1; j >=0; --j){
                if(i == m){
                    if(j + 1 < n && p[j + 1] == '*'){
                        nextDp[j] = nextDp[j + 2];
                    }else{
                        nextDp[j] = 0;
                    }
                    continue;
                }

                bool res = false;

                if(s[i] == p[j] || p[j] == '.'){
                    if(j + 1 < p.size() && p[j + 1] == '*'){
                        res = nextDp[j + 2] || dp[j + 2] || dp[j];
                    }else{
                        res = dp[j + 1];
                    }
                }else{
                    if(j + 1 < p.size() && p[j + 1] == '*') res = nextDp[j + 2];
                }

                nextDp[j] = res;
            }
            dp = nextDp;
        }
        return dp[0];
    }
};

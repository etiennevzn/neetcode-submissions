class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);

        for(int j = 0; j < n + 1; ++j){
            dp[j] = n - j;
        }

        for(int i = m - 1; i >= 0; --i){
            vector<int> nextDp(n + 1, 0);
            nextDp[n] = m - i;

            for(int j = n - 1; j >= 0; --j){
                if(word1[i] == word2[j]){
                    nextDp[j] = dp[j+1];
                }else{
                    nextDp[j] = 1 + min(dp[j], min(nextDp[j+1], dp[j+1]));
                }
            }

            dp = nextDp;
        }

        return dp[0];
    }
};

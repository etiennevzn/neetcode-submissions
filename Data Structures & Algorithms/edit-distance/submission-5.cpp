class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m < n){
            swap(m, n);
            swap(word1, word2);
        }

        vector<int> dp(n + 1, 0);

        for(int j = 0; j < n + 1; ++j){
            dp[j] = n - j;
        }

        vector<int> nextDp(n + 1, 0);
        for(int i = m - 1; i >= 0; --i){
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

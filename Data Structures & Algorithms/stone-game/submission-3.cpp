class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int begin = n - 1; begin >= 0; --begin){
            for(int end = begin; end < n; ++end){
                if(begin == end){
                    dp[begin][end] = piles[begin];
                    continue;
                }
                int b = piles[begin] - dp[begin + 1][end];
                int e = piles[end] - dp[begin][end - 1];
                dp[begin][end] = max(b, e);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
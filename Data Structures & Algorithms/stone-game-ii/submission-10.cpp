class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        suffixSum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; --i){
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        
        for(int i = n - 1; i >= 0; --i){
            for(int m = 1; m <= n; ++m){
                int res = 0;
                for(int j = 0; j < 2*m && i + j < piles.size(); ++j){
                    res = max(res, suffixSum[i] - dp[i + j + 1][max(m, j+1)]); 
                }
                dp[i][m] = res;
            }
        }

        return dp[0][1];
    }
};
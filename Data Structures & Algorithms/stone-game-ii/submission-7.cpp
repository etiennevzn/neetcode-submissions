class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int m, vector<int>& piles, vector<int>& suffixSum){
        if(i == piles.size()) return 0;
        if(memo[i][m] != -1) return memo[i][m];

        int res = 0;
        for(int j = 0; j < 2*m && i + j < piles.size(); ++j){
            res = max(res, suffixSum[i] - dfs(i + j + 1, max(m, j+1), piles, suffixSum));
        }
        return memo[i][m] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; --i){
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        memo.resize(n, vector<int>(n + 1, -1));
        return dfs(0, 1, piles, suffixSum);
    }
};
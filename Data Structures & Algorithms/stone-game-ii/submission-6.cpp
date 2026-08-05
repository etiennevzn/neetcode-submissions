class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int m, vector<int>& piles, vector<int>& suffixSum){
        if(i >= piles.size()) return 0;
        if(memo[i][m] != -1) return memo[i][m];

        int res = 0;
        for(int j = 0; j < 2*m && i + j < piles.size(); ++j){
            res = max(res, suffixSum[i] - dfs(i + j + 1, max(m, j+1), piles, suffixSum));
        }
        return memo[i][m] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> suffixSum = piles;
        for(int i = piles.size() - 2; i >= 0; --i){
            suffixSum[i] += suffixSum[i + 1];
        }
        suffixSum.push_back(0);
        memo.resize(piles.size(), vector<int>(piles.size() + 1, -1));
        return dfs(0, 1, piles, suffixSum);
    }
};
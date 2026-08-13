class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int begin, int end, vector<int>& piles){
        if(begin > end) return 0;
        if(memo[begin][end] != -1) return memo[begin][end];
        int b = piles[begin] - dfs(begin + 1, end, piles);
        int e = piles[end] - dfs(begin, end - 1, piles);
        return memo[begin][end] = max(b, e);
    }
public:
    bool stoneGame(vector<int>& piles) {
        memo.resize(piles.size(), vector<int>(piles.size(), -1));
        return dfs(0, piles.size() - 1, piles) > 0;
    }
};
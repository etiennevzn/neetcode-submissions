class Solution {
private:
    vector<int> memo;
    int dfs(int i, vector<int>& stoneValue){
        if(i == stoneValue.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int take1 = stoneValue[i] - dfs(i + 1, stoneValue);
        int take2 = INT_MIN;
        int take3 = INT_MIN;
        if(i + 1 < stoneValue.size()) take2 = stoneValue[i] + stoneValue[i + 1] - dfs(i + 2, stoneValue);
        if(i + 2 < stoneValue.size()) take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dfs(i + 3, stoneValue);

        return memo[i] = max(take1, max(take2, take3));
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memo.resize(stoneValue.size(), -1);
        int diff = dfs(0, stoneValue);
        return diff == 0 ? "Tie" : diff > 0 ? "Alice" : "Bob";
    }
};
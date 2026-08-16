class Solution {
private:
    vector<int> memo;
    int dfs(int i, vector<int>& stoneValue){
        if(i == stoneValue.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int res = INT_MIN, taken = 0, n = stoneValue.size();
        for(int j = i; j < min(i + 3, n); ++j){
            taken += stoneValue[j];
            res = max(res, taken - dfs(j + 1, stoneValue));
        }

        return memo[i] = res;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memo.resize(stoneValue.size(), -1);
        int diff = dfs(0, stoneValue);
        return diff == 0 ? "Tie" : diff > 0 ? "Alice" : "Bob";
    }
};
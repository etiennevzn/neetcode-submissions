class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; --i){
            int res = INT_MIN, taken = 0;
            for(int j = i; j < min(i + 3, n); ++j){
                taken += stoneValue[j];
                res = max(res, taken - dp[j + 1]);
            }
            dp[i] = res;
        }

        return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob";
    }
};